#pragma once

#include <eventloop/NonCopyable.hpp>
#include <unordered_map>
#include <vector>
#include <sys/epoll.h>

namespace dan { namespace eventloop {

class AnEvent;


//
// one epoll per thread
//
class EventLoop : NonCopyable
{
public:
    EventLoop() noexcept;
    ~EventLoop();

    bool Subscribe(AnEvent* pstEvent) noexcept;
    void Loop() noexcept;
private:
    void Fire(int iReady) noexcept;
private:
    int                                 m_iEpollFd;         // epoll fd
    std::unordered_map<int, AnEvent*>   m_stEvents;
    std::vector<struct epoll_event>     m_stActiveEvents;
};

}}
