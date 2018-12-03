#include <eventloop/TcpServer.h>
#include <eventloop/EventLoop.h>
#include <eventloop/AnEvent.h>
#include <eventloop/AnSocket.h>
#include <eventloop/AnConn.h>

#include <sys/socket.h>
#include <netdb.h>
#include <chrono>

namespace dan { namespace eventloop {

TcpServer::TcpServer(int iPort, const char* szAddress) noexcept:
    m_stServerSocket(new AnSocket(true, iPort, szAddress)),
    m_pstEventLoop(new EventLoop()),
    m_pstServerEvent(new AnEvent(m_stServerSocket->Fd(), m_pstEventLoop.get())),
    m_stThreadID(std::this_thread::get_id())
{}

TcpServer::~TcpServer()
{}

void TcpServer::Run() noexcept
{
    // init
    PreRun();
    // register
    m_pstServerEvent->SubscribeRead(true);
    // run
    m_pstEventLoop->Loop();
}

void TcpServer::PreRun() noexcept
{
    // read
    m_pstServerEvent->FiredRead([this](){

        int iClientFd = m_stServerSocket->Accept();

        if(iClientFd == -1)
        {
            return;
        }
        
        printf("new client\n");
        uint64_t ulUid = this->GenUid();
        std::unique_ptr<AnConn> pstConn = std::unique_ptr<AnConn>(new AnConn(this, iClientFd, ulUid, m_pstEventLoop.get()));
        m_stConns[ulUid] = std::move(pstConn);

    });

    // write
    m_pstServerEvent->FiredWrite([this](){
        printf("oh~~~~~\n");
    });

    // error
    m_pstServerEvent->FiredError([this](){
        printf("oh~~~~~\n");
    });

    // close
    m_pstServerEvent->FiredClose([this](){
    });

}

uint64_t TcpServer::GenUid()
{
    uint64_t ulUid = (std::chrono::duration_cast<std::chrono::microseconds> (std::chrono::steady_clock::now().time_since_epoch())).count();
    return ulUid;
}

}}
