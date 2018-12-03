#pragma once

#include <eventloop/NonCopyable.hpp>
#include <stdint.h>
#include <functional>

namespace dan { namespace eventloop {

class EventLoop;


// 
// one event per thread
//
class AnEvent : NonCopyable
{
public:
    using firedfunc = std::function<void()>;
public:
    AnEvent() = delete;
    AnEvent(int iFd, EventLoop* pstEventLoop) noexcept;
    ~AnEvent() = default;

    bool SubscribeRead(bool bWant) noexcept;        //
    bool SubscribeWrite(bool bWant) noexcept;       //
    bool SubscribeNone() noexcept;

    int  OwnerFd(){return m_iOwnerFd;}              //
    uint32_t EpollEvent(){return m_dwEpollEvent;}

    void FiredRead (firedfunc ff){m_stFiredRead  = std::move(ff);}
    void FiredWrite(firedfunc ff){m_stFiredWrite = std::move(ff);}
    void FiredError(firedfunc ff){m_stFiredError = std::move(ff);}
    void FiredClose(firedfunc ff){m_stFiredClose = std::move(ff);}

    void FiredRead() {if(m_stFiredRead)  m_stFiredRead();}
    void FiredWrite(){if(m_stFiredWrite) m_stFiredWrite();}
    void FiredError(){if(m_stFiredError) m_stFiredError();}
    void FiredClose(){if(m_stFiredClose) m_stFiredClose();}
private:
    int         m_iOwnerFd;
    EventLoop*  m_pstEventLoop;         
    uint32_t    m_dwEpollEvent;

    firedfunc    m_stFiredRead;
    firedfunc    m_stFiredWrite;
    firedfunc    m_stFiredError;
    firedfunc    m_stFiredClose;
};

}}
