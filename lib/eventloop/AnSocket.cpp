#include <eventloop/AnSocket.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <string.h>
#include <fcntl.h>
#include <cstdio>
#include <errno.h>
#include <cstdlib>
#include <unistd.h>

namespace dan { namespace eventloop {

AnSocket::AnSocket(bool bIsServer, int iPort, const char* szAddress) noexcept:
    m_iOwnerFd(-1),
    m_iPort(iPort),
    m_bIsServer(bIsServer)
{
    if(bIsServer == true)
    {
        //
        // for server
        //
        struct ::addrinfo  stHints;
        struct ::addrinfo* pstResult;

        ::bzero(&stHints, sizeof(struct addrinfo));
        stHints.ai_family   = AF_INET;
        stHints.ai_socktype = SOCK_STREAM;
        stHints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST | AI_NUMERICSERV;
        char szPort[6] = {0};
        ::snprintf(szPort, 6, "%d", iPort);

        if(::getaddrinfo(szAddress, szPort, &stHints, &pstResult) < 0)
        {
            printf("ERROR: getaddrinfo failed: %s\n", ::strerror(errno));
            ::exit(-1);
        }

        for(struct ::addrinfo* pstCurr = pstResult; pstCurr != nullptr; pstCurr = pstResult->ai_next)
        {
            m_iOwnerFd = ::socket(pstCurr->ai_family, pstCurr->ai_socktype, pstCurr->ai_protocol);
            int iOptval = 1;
            if(m_iOwnerFd == -1 || 
               ::setsockopt(m_iOwnerFd, SOL_SOCKET, SO_REUSEADDR, &iOptval, sizeof(iOptval)) == -1 ||
               ::setsockopt(m_iOwnerFd, IPPROTO_TCP, TCP_NODELAY, &iOptval, sizeof(iOptval)) == -1 ||
               ::bind(m_iOwnerFd, pstResult->ai_addr, pstResult->ai_addrlen) == -1 ||
               ::listen(m_iOwnerFd, 64) == -1)
            {
                printf("ERROR: init socket failed: %s\n", ::strerror(errno));
                if(m_iOwnerFd != -1)
                {
                    ::close(m_iOwnerFd);
                }
                continue;
            }
            else
            {
                printf("listen fd:%d %s::%d\n", m_iOwnerFd, szAddress, iPort);
            }
        }

        if(pstResult != nullptr)
        {
            ::freeaddrinfo(pstResult);
            pstResult = nullptr;
        }

        if(m_iOwnerFd == -1)
        {
            printf("ERROR: init socket failed\n");
            ::exit(-1);
        }

    }
    else
    {
        //
        // for client
        //
        struct ::addrinfo  stHints;
        struct ::addrinfo* pstResult;

        ::bzero(&stHints, sizeof(struct addrinfo));
        stHints.ai_family   = AF_INET;
        stHints.ai_socktype = SOCK_STREAM;
        stHints.ai_flags    = AI_NUMERICHOST | AI_NUMERICSERV;
       
        char szPort[6] = {0};
        ::snprintf(szPort, 6, "%d", iPort);

        if(::getaddrinfo(szAddress, szPort, &stHints, &pstResult) < 0)
        {
            printf("ERROR: getaddrinfo failed: %s\n", ::strerror(errno));
            ::exit(-1);
        }

        for(struct ::addrinfo* pstCurr = pstResult; pstCurr != nullptr; pstCurr = pstResult->ai_next)
        {
            m_iOwnerFd = ::socket(pstCurr->ai_family, pstCurr->ai_socktype, pstCurr->ai_protocol);
            int iOptval = 1;
            if(m_iOwnerFd == -1 || 
               ::setsockopt(m_iOwnerFd, SOL_SOCKET, SO_REUSEADDR, &iOptval, sizeof(iOptval)) == -1 ||
               ::setsockopt(m_iOwnerFd, IPPROTO_TCP, TCP_NODELAY, &iOptval, sizeof(iOptval)) == -1)
            {
                printf("ERROR: init socket failed: %s\n", ::strerror(errno));
                if(m_iOwnerFd != -1)
                {
                    ::close(m_iOwnerFd);
                }
                continue;
            }
        }

        if(pstResult != nullptr)
        {
            ::freeaddrinfo(pstResult);
            pstResult = nullptr;
        }

        if(m_iOwnerFd == -1)
        {
            printf("ERROR: init socket failed\n");
            ::exit(-1);
        }

    }

    // close exec
    if(m_iOwnerFd != -1)
    {
        int iFlags = ::fcntl(m_iOwnerFd, F_GETFD, 0);
        if(iFlags == -1)
            ::exit(-1);
        iFlags |= FD_CLOEXEC;
        if(::fcntl(m_iOwnerFd, F_SETFD, iFlags) == -1)
            ::exit(-1);
    }
}

AnSocket::AnSocket(int iClientFd) noexcept:
    m_iOwnerFd(iClientFd),
    m_iPort(-1),
    m_bIsServer(false)
{}

AnSocket::~AnSocket()
{
    if(m_iOwnerFd != -1)
    {
        ::close(m_iOwnerFd);
    }
}

int AnSocket::Accept()
{
    if(m_bIsServer == false)
    {
        return -1;
    }


    struct ::sockaddr_in stClientAddr;
    ::socklen_t stSocklen = sizeof(struct ::sockaddr_in);
    void* pstTmp = static_cast<void*> (&stClientAddr);

    int iClientFd = -1;
    while(true)
    {
        iClientFd = ::accept4(m_iOwnerFd, 
                              static_cast<struct sockaddr*>(pstTmp), 
                              &stSocklen, 
                              SOCK_CLOEXEC | SOCK_NONBLOCK);

        if(iClientFd == -1)
        {
            switch(errno)
            {
                case EINTR:
                case ECONNABORTED:      // client close
                case EAGAIN:
                case EPERM:
                case EMFILE:
                case EPROTO:
                {
                    return -1;
                }
                default:
                {
                    printf("ERROR: accept failed :%s\n", ::strerror(errno));
                    ::exit(-1);
                }
            }
        }
        else
        {
            break;
        }
    }
    return iClientFd;
}

ssize_t AnSocket::Recv(void* pstBuffer, size_t dwLength)
{
    if(m_bIsServer && m_iOwnerFd != -1)
    {
        return -1;
    }

    return ::recv(m_iOwnerFd, pstBuffer, dwLength, 0);
}

ssize_t AnSocket::Send(void* pstBuffer, size_t dwLength)
{
    if(m_bIsServer && m_iOwnerFd != -1)
    {
        return -1;
    }

    return ::send(m_iOwnerFd, pstBuffer, dwLength, 0);
}


}}
