#include <eventloop/AnConn.h>
#include <eventloop/AnSocket.h>
#include <eventloop/AnEvent.h>
#include <eventloop/AnBuffer.h>
#include <eventloop/TcpServer.h>

#include <string.h>

namespace dan { namespace eventloop {

AnConn::AnConn(TcpServer* pstTcpServer, int iClientFd, uint64_t ulUid, EventLoop* m_pstEventLoop, uint32_t dwAvgSeqSize) noexcept:
    m_ulUid(ulUid),
    m_pstClientSocket(new AnSocket(iClientFd)),
    m_pstClientEvent(new AnEvent(iClientFd, m_pstEventLoop)),
    m_pstBackBuffer(new AnBuffer(1024*1024*8)),
    m_dwAvgSeqSize(dwAvgSeqSize),
    m_pstOwnerServer(pstTcpServer)
{
    // init
    PreRun();
    m_pstClientEvent->SubscribeRead(true);
}

AnConn::~AnConn()
{}

void AnConn::PreRun() noexcept
{
    // read
    m_pstClientEvent->FiredRead([this](){
        
        auto ulWriteable  = m_pstBackBuffer->Writeable();
        auto ulReadable = m_pstBackBuffer->Readable();
        auto ulWriteIndex = m_pstBackBuffer->WriteIndex();

       
        if(ulWriteable <= (m_dwAvgSeqSize * 5))
        {
            if(m_pstBackBuffer->Processed() >= (m_dwAvgSeqSize * 3))
            {
                // move to front
                ::memcpy(m_pstBackBuffer->BeginPtr(), m_pstBackBuffer->ReadPtr(), ulReadable);
            }

            ulWriteable = m_pstBackBuffer->Writeable();
            if(ulWriteable <= (m_dwAvgSeqSize * 5))
            {
                // resize to x2
                if(m_pstBackBuffer->MakeSpace() == false)
                {
                    // no more space (may be under attacked)
                    // FIXME here just kill
                    this->Close();
                }
            }
        }   
        
        ulWriteable  = m_pstBackBuffer->Writeable();
        auto lCount = m_pstClientSocket->Recv(m_pstBackBuffer->WritePtr(), ulWriteable);
        if(lCount == 0)
        {
            printf("client close\n");
            this->Close();
        }
        else if(lCount > 0)
        {
            m_pstBackBuffer->SetWriteIndex(ulWriteIndex + lCount);
        }
        else
        {
            if(errno != EAGAIN && errno != EINTR)
            {
                //TODO error!  just close
                this->Close();
            }
        }

    });

    // write
    m_pstClientEvent->FiredWrite([this](){
    });

    // error
    m_pstClientEvent->FiredError([this](){
    });

    // close
    m_pstClientEvent->FiredClose([this](){
    });
}

void AnConn::Close() noexcept{m_pstClientEvent->SubscribeNone(); m_pstOwnerServer->RemoveConn(m_ulUid);}

}}
