#pragma once

#include <eventloop/NonCopyable.hpp>
#include <cstdio>

namespace dan { namespace eventloop {

class AnSocket: NonCopyable
{
public:
    AnSocket(bool bIsServer, int iPort, const char* szAddress) noexcept;
    AnSocket(int iClientFd) noexcept;
    ~AnSocket();
    int Fd(){return m_iOwnerFd;}
    int Accept();
    ssize_t Recv(void* pstBuffer, size_t dwLength);
    ssize_t Send(void* pstBuffer, size_t dwLength);
private:
    int  m_iOwnerFd;
    int  m_iPort;
    bool m_bIsServer;

};


}}
