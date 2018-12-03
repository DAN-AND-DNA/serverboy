#include <eventloop/AnConn.h>
#include <eventloop/AnSocket.h>
#include <eventloop/AnEvent.h>
#include <eventloop/AnBuffer.h>
#include <eventloop/TcpServer.h>

#include <iostream> // for test

#include <string.h>

namespace dan { namespace eventloop {

AnConn::AnConn(TcpServer* pstTcpServer, int iClientFd, uint64_t ulUid, EventLoop* m_pstEventLoop, uint32_t dwAvgSeqSize) noexcept:
    m_ulUid(ulUid),
    m_pstClientSocket(new AnSocket(iClientFd)),
    m_pstClientEvent(new AnEvent(iClientFd, m_pstEventLoop)),
    m_pstInBuffer(new AnBuffer(1024*1024*8)),
    m_pstOutBuffer(new AnBuffer(1024*1024*8)),
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
        
        auto ulWriteable  = m_pstInBuffer->Writeable();
        auto ulReadable = m_pstInBuffer->Readable();
        auto ulWriteIndex = m_pstInBuffer->WriteIndex();

       
        if(ulWriteable <= (m_dwAvgSeqSize * 5))
        {
            if(m_pstInBuffer->Processed() >= (m_dwAvgSeqSize * 3))
            {
                // move to front
                ::memcpy(m_pstInBuffer->BeginPtr(), m_pstInBuffer->ReadPtr(), ulReadable);
            }

            ulWriteable = m_pstInBuffer->Writeable();
            if(ulWriteable <= (m_dwAvgSeqSize * 5))
            {
                // resize to x2
                if(m_pstInBuffer->MakeSpace() == false)
                {
                    // no more space (may be under attacked)
                    // FIXME here just kill
                    this->Close();
                }
            }
        }   
        
        ulWriteable  = m_pstInBuffer->Writeable();
        auto lCount = m_pstClientSocket->Recv(m_pstInBuffer->WritePtr(), ulWriteable);
        
        auto now = std::chrono::high_resolution_clock::now();
        
        if(lCount == 0)
        {
            printf("client close\n");
            this->Close();
        }
        else if(lCount > 0)
        {
            m_pstInBuffer->SetWriteIndex(ulWriteIndex + lCount);

            //TODO deal msg
            //=========================== just test, do not safety=============================
            //
            auto ulReadable = m_pstInBuffer->Readable();
            printf("receive %lu bytes\n deal %lu bytes\n", ulReadable, ulReadable);

            //FIXME speed up
            ::memcpy(m_pstOutBuffer->WritePtr(), m_pstInBuffer->ReadPtr(), ulReadable);

            m_pstInBuffer->SetReadIndex(m_pstInBuffer->ReadIndex() + ulReadable);
            m_pstOutBuffer->SetWriteIndex(m_pstOutBuffer->WriteIndex() + ulReadable);
         
/*
            std::string s2(reinterpret_cast<const char*>(m_pstOutBuffer->ReadPtr()), m_pstOutBuffer->Readable());
            printf("msg2:%s \n", s2.c_str());
         
*/

            auto us = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - now).count();
            std::cout <<"cosume "<<double(us) <<" us"<< std::endl;


            auto ulSended = m_pstClientSocket->Send(m_pstOutBuffer->ReadPtr(), ulReadable);

            // send dirctly
            if(ulSended > 0)
            {
                m_pstOutBuffer->SetReadIndex(m_pstOutBuffer->ReadIndex() + ulSended);
                if(m_pstInBuffer->Readable() == 0)
                {
                    m_pstClientEvent->SubscribeWrite(false);
                }
                else if(ulSended > 0)
                {
                    m_pstClientEvent->SubscribeWrite(true);
                }
            }
            else
            {
                this->Close();
            }


            //
            //
            //========================================test==========================================


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
        auto ulReadable = m_pstOutBuffer->Readable();
        
        if(ulReadable == 0)
        {
            m_pstClientEvent->SubscribeWrite(false);
            return;
        }

        auto ulSended = m_pstClientSocket->Send(m_pstOutBuffer->ReadPtr(), ulReadable);

        if(ulSended >0)
        {
            m_pstOutBuffer->SetReadIndex(m_pstOutBuffer->ReadIndex() + ulSended);
            if(m_pstOutBuffer->Readable() == 0)
            {
                printf("echo\n");
                m_pstClientEvent->SubscribeWrite(false);
                return;
            }
        }

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
