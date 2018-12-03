#include <eventloop/EventLoop.h>
#include <eventloop/AnEvent.h>

#include <sys/epoll.h>
#include <unistd.h>
#include <cstdio>
#include <cstring>
#include <errno.h>
#include <cstdlib>

namespace 
{

constexpr int iTimeout = 10000;

}

namespace dan { namespace eventloop {

EventLoop::EventLoop() noexcept:
    m_iEpollFd(::epoll_create1(EPOLL_CLOEXEC)),
    m_stEvents(),
    m_stActiveEvents(16)
{
    if(m_iEpollFd == -1)
    {
        ::printf("ERROR: epoll create failed:%s\n", ::strerror(errno));
        ::exit(-1);
    }
}

EventLoop::~EventLoop()
{
    if(m_iEpollFd != -1)
    {
        ::close(m_iEpollFd);
    }
}

bool EventLoop::Subscribe(AnEvent* pstEvent) noexcept
{
    if(pstEvent == nullptr || pstEvent->OwnerFd() < 0)
    {
        printf("subscribe failed\n");
        return false;
    }

    struct ::epoll_event stEpollEvent;
    ::bzero(&stEpollEvent, sizeof(struct ::epoll_event));
    stEpollEvent.data.ptr = pstEvent;
    stEpollEvent.events = pstEvent->EpollEvent();
    auto stEpollCtl = EPOLL_CTL_ADD;

    auto it = m_stEvents.find(pstEvent->OwnerFd());  
    if(it != m_stEvents.end())
    {
        //
        // del or change
        //
        if(stEpollEvent.events == 0)
        {
            stEpollCtl = EPOLL_CTL_DEL;
        }
        else
        {
            stEpollCtl = EPOLL_CTL_MOD;
        }
        
        if(::epoll_ctl(m_iEpollFd, stEpollCtl, it->first, &stEpollEvent) == -1)
        {
            ::printf("Error:epoll_ctl error:%s\n", ::strerror(errno));
            if(errno == ENOENT)
            {
                errno = 0;  //ingore error
            }
            else
            {
                ::exit(-1);
            }
        }
        else
        {
            if(stEpollCtl == EPOLL_CTL_DEL)
            {
                m_stEvents.erase(it);
            }
        }
    }
    else
    {
        //
        // add
        //
        if(::epoll_ctl(m_iEpollFd, stEpollCtl, pstEvent->OwnerFd(), &stEpollEvent) == -1)
        {
            ::printf("Error:epoll_ctl error:%s\n", ::strerror(errno));
            if(errno == EEXIST)
            {
                errno = 0;  //ingore error
            }
            else
            {
                ::exit(-1);
            }
        }
        else
        {
            m_stEvents.insert({pstEvent->OwnerFd(), pstEvent});
        }
    }

    return true;
}

void EventLoop::Loop() noexcept
{
    int iReady = 0;

    while(iReady >= 0 || (iReady == -1 && errno == EINTR))
    {
        iReady = ::epoll_wait(m_iEpollFd, m_stActiveEvents.data(), static_cast<int>(m_stActiveEvents.size()), ::iTimeout);
        this->Fire(iReady);
    }
    
    // TODO error
}

void EventLoop::Fire(int iReady) noexcept
{
    if(iReady == 0)
        return;


    printf("get events\n");
    for(int i = 0; i < iReady; ++i)
    {
        // read
        if(m_stActiveEvents[i].events & (EPOLLIN | EPOLLPRI | EPOLLRDHUP)) reinterpret_cast<AnEvent*>(m_stActiveEvents[i].data.ptr)->FiredRead();
        // write
        if(m_stActiveEvents[i].events & (EPOLLOUT)) reinterpret_cast<AnEvent*>(m_stActiveEvents[i].data.ptr)->FiredWrite(); 
        // error
        if(m_stActiveEvents[i].events & (EPOLLERR))  reinterpret_cast<AnEvent*>(m_stActiveEvents[i].data.ptr)->FiredError();
        // the client closed 
        if(m_stActiveEvents[i].events & (EPOLLHUP))  reinterpret_cast<AnEvent*>(m_stActiveEvents[i].data.ptr)->FiredClose();
    }

    if(iReady == static_cast<int>(m_stActiveEvents.size()))
    {
        m_stActiveEvents.resize(m_stActiveEvents.size() * 2);
    }

}





}}
