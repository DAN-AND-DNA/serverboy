#pragma once

#include <memory>
#include <eventloop/NonCopyable.hpp>

namespace dan { namespace eventloop {

class AnEvent;
class AnSocket;
class EventLoop;
class AnBuffer;
class TcpServer;

class AnConn
{
public:
    AnConn(TcpServer* pstTcpServer,int iClientFd, uint64_t ulUid, EventLoop* m_pstEventLoop, uint32_t dwAvgSeqSize = 40) noexcept;
    ~AnConn();
private:
    void                        PreRun() noexcept;
    void                        Close() noexcept;
private:
    uint64_t                    m_ulUid;
    std::unique_ptr<AnSocket>   m_pstClientSocket;
    std::unique_ptr<AnEvent>    m_pstClientEvent;
    std::unique_ptr<AnBuffer>   m_pstInBuffer;
    std::unique_ptr<AnBuffer>   m_pstOutBuffer;
    uint32_t                    m_dwAvgSeqSize;
    TcpServer*                  m_pstOwnerServer;
};


}}
