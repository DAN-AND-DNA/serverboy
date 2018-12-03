#include <eventloop/AnEvent.h>
#include <eventloop/EventLoop.h>
#include <sys/epoll.h>

namespace dan { namespace eventloop {

AnEvent::AnEvent(int iFd, EventLoop* pstEventLoop) noexcept:
    m_iOwnerFd(iFd),
    m_pstEventLoop(pstEventLoop),
    m_dwEpollEvent(0)
{}


bool AnEvent::SubscribeRead(bool bWant) noexcept
{
    if(bWant == true)
    {
        m_dwEpollEvent |= EPOLLIN;
        m_dwEpollEvent |= EPOLLPRI;
    }
    else
    {
        m_dwEpollEvent &= ~EPOLLIN;
        m_dwEpollEvent &= ~EPOLLPRI;
    }
    return m_pstEventLoop->Subscribe(this);
}

bool AnEvent::SubscribeWrite(bool bWant) noexcept
{
    if(bWant == true)
    {
        m_dwEpollEvent |= EPOLLOUT;
    }
    else
    {
        m_dwEpollEvent &= ~EPOLLOUT;
    }

    return m_pstEventLoop->Subscribe(this);
}

bool AnEvent::SubscribeNone() noexcept
{
    m_dwEpollEvent = 0;
    return m_pstEventLoop->Subscribe(this);
}


}}
