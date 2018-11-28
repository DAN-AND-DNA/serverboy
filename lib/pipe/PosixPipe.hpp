#pragma once

#include <unistd.h>
#include <streambuf>
#include <vector>
#include <string>
#include <cstring>

namespace dan { namespace pipe {


// 管道
template<class CharT, class Traits = std::char_traits<CharT>>
class PosixPipe
{
public:
    using char_type = CharT;
    using traits_type = Traits;
    using int_type = typename Traits::int_type;
    using pos_type = typename Traits::pos_type;
    using off_type = typename Traits::off_type;
  

    int EndPoint0(){return m_iEndPoint0;}
    int EndPoint1(){return m_iEndPoint1;}

    void AssignEndPoint0(int iEP0){m_iEndPoint0 = iEP0;}
    void AssignEndPoint1(int iEP1){m_iEndPoint1 = iEP1;}
public:
    PosixPipe();
    ~PosixPipe();
    PosixPipe(PosixPipe&& stR);
    explicit PosixPipe(int iEP0, int iEP1);
    PosixPipe& operator=(PosixPipe&& stR);
    ssize_t Write(const char* pstData, size_t ulCount);
    ssize_t Read(char* pstData, size_t ulCount);
    bool IsOpened();
    void Close();

private:
    int m_iEndPoint0;
    int m_iEndPoint1;
};


// 缓冲
template<class CharT, class Traits = std::char_traits<CharT>>
struct PosixPipeBuf: public std::basic_streambuf<CharT, Traits>
{
public:
    using pipe_type = PosixPipe<CharT, Traits>;
    using char_type = CharT;
    using traits_type = Traits;
    using int_type = typename Traits::int_type;
    using pos_type = typename Traits::pos_type;
    using off_type = typename Traits::off_type;

    PosixPipeBuf();
    PosixPipeBuf(pipe_type&& p);
    int_type overflow(int_type ch = traits_type::eof()) override;
    int sync() override;
    int_type underflow() override;

    pipe_type& Pipe() & {return m_stPipe;}

private:
    pipe_type m_stPipe;
    std::vector<char_type> m_stWriteBuf;
    std::vector<char_type> m_stReadBuf;

    bool WriteImpl();
};


// read流
template<class CharT, class Traits = std::char_traits<CharT>>
class PosixPipeistream: public std::basic_istream<CharT, Traits>
{
public:
    using pipe_type = PosixPipe<CharT, Traits>;
    using char_type = CharT;
    using traits_type = Traits;
    using int_type = typename Traits::int_type;
    using pos_type = typename Traits::pos_type;
    using off_type = typename Traits::off_type;

    PosixPipeistream();
    pipe_type& Pipe() & {return m_stBuf.Pipe();}
private:
    PosixPipeBuf<CharT, Traits> m_stBuf;
};

// write流
template<class CharT, class Traits = std::char_traits<CharT>>
class PosixPipeostream: public std::basic_ostream<CharT, Traits>
{
public:
    using pipe_type = PosixPipe<CharT, Traits>;
    using char_type = CharT;
    using traits_type = Traits;
    using int_type = typename Traits::int_type;
    using pos_type = typename Traits::pos_type;
    using off_type = typename Traits::off_type;


    PosixPipeostream();
    pipe_type& Pipe() & {return m_stBuf.Pipe();}

private:
    PosixPipeBuf<CharT, Traits> m_stBuf;
};



// write流
template<class CharT, class Traits = std::char_traits<CharT>>
class PosixPipeiostream: public std::basic_iostream<CharT, Traits>
{
public:
    using pipe_type = PosixPipe<CharT, Traits>;
    using char_type = CharT;
    using traits_type = Traits;
    using int_type = typename Traits::int_type;
    using pos_type = typename Traits::pos_type;
    using off_type = typename Traits::off_type;


    PosixPipeiostream();
private:
    PosixPipeBuf<CharT, Traits> m_stBuf;

};



//
//
//
//


// 管道
template<class CharT, class Traits> 
PosixPipe<CharT, Traits>::PosixPipe():
    m_iEndPoint0(-1),
    m_iEndPoint1(-1)
{
    int iFds[2];
    if(::pipe(iFds) == -1)
    {
        //TODO
    }

    m_iEndPoint0 = iFds[0];
    m_iEndPoint1 = iFds[1];
}

template<class CharT, class Traits> 
PosixPipe<CharT, Traits>::~PosixPipe()
{
    if(m_iEndPoint0 != -1)
    {
        ::close(m_iEndPoint0);
    }

    if(m_iEndPoint1 != -1)
    {
        ::close(m_iEndPoint1);
    }
}

template<class CharT, class Traits> 
PosixPipe<CharT, Traits>::PosixPipe(PosixPipe&& stR):
    m_iEndPoint0(stR.m_iEndPoint0),
    m_iEndPoint1(stR.m_iEndPoint1)
{
    stR.m_iEndPoint0 = -1;
    stR.m_iEndPoint1 = -1;
}

template<class CharT, class Traits> 
PosixPipe<CharT, Traits>::PosixPipe(int iEP0, int iEP1):
    m_iEndPoint0(iEP0),
    m_iEndPoint1(iEP1)
{}

template<class CharT, class Traits> 
PosixPipe<CharT, Traits>& PosixPipe<CharT, Traits>::operator=(PosixPipe&& stR)
{
    m_iEndPoint0 = stR.m_iEndPoint0;
    m_iEndPoint1 = stR.m_iEndPoint1;
   
    stR.m_iEndPoint0 = -1;
    stR.m_iEndPoint1 = -1;

    return *this;
}

template<class CharT, class Traits>  
ssize_t PosixPipe<CharT, Traits>::Write(const char* pstData, size_t ulCount)
{
    ssize_t lLen = ::write(m_iEndPoint1, pstData, ulCount);
    if(lLen == -1)
    {
        //TODO 
    }
    return lLen;
}

template<class CharT, class Traits> 
ssize_t PosixPipe<CharT, Traits>::Read(char* pstData, size_t ulCount)
{
    ssize_t lLen = ::read(m_iEndPoint0, pstData, ulCount);
    if(lLen == -1)
    {
        //TODO
    }
    return lLen;
}

template<class CharT, class Traits> 
bool PosixPipe<CharT, Traits>::IsOpened()
{
    return (m_iEndPoint0 != -1 && m_iEndPoint1 != -1);
}

template<class CharT, class Traits> 
void PosixPipe<CharT, Traits>::Close()
{
    if(m_iEndPoint0 != -1)
    {
        ::close(m_iEndPoint0);
        m_iEndPoint0 = -1;
    }

    if(m_iEndPoint1 != -1)
    {
        ::close(m_iEndPoint1);
        m_iEndPoint1 = -1;
    }
}

//  缓冲
template<class CharT, class Traits>
PosixPipeBuf<CharT, Traits>::PosixPipeBuf():
    m_stPipe(),
    m_stWriteBuf(1024),
    m_stReadBuf(1024)
{
    // 头 尾 尾 表示无可读
    this->setg(m_stReadBuf.data(), m_stReadBuf.data() + 128, m_stReadBuf.data() + 128);
    this->setp(m_stWriteBuf.data(), m_stWriteBuf.data() + m_stWriteBuf.size());
}


template<class CharT, class Traits>
PosixPipeBuf<CharT, Traits>::PosixPipeBuf(pipe_type&& p):
    m_stPipe(std::move(p)),
    m_stWriteBuf(1024),
    m_stReadBuf(1024)
{
    this->setg(m_stReadBuf.data(), m_stReadBuf.data() + 128, m_stReadBuf.data() + 128);
    this->setp(m_stWriteBuf.data(), m_stWriteBuf.data() + m_stWriteBuf.size());
}

template<class CharT, class Traits>
bool PosixPipeBuf<CharT, Traits>::WriteImpl()
{
    if(!m_stPipe.IsOpened())
        return false;

    // 把放置区的数据写到管道
    char_type* pstBase = this->pbase();
    std::ptrdiff_t diff = this->pptr() - pstBase;

    auto len = m_stPipe.Write(pstBase, static_cast<size_t>(diff));

    
    if(len < diff)
    {
        std::move(pstBase + len, pstBase + diff, pstBase);
    }
    else if(len == 0)
    {
        // diff == len == 0
        return false;
    }

    this->pbump(static_cast<int>(-len));
    return true;
   
}

template<class CharT, class Traits>
typename PosixPipeBuf<CharT, Traits>::int_type PosixPipeBuf<CharT, Traits>::overflow(int_type ch)
{
    if(ch != traits_type::eof() && m_stPipe.IsOpened())
    {
        if(this->pptr() == this->epptr())
        {
            //如果放置区满了
            //1. 先把放置区的数据输出给管道
            bool bIsWrited = this->WriteImpl();
            //2. 然后写入放置区
            *(this->pptr()) = static_cast<char_type>(ch);
            this->pbump(1);
            if(bIsWrited)
                return ch;

        }
        else
        {
            //放置区没有满
            //1. 直接写入放置区
            *(this->pptr()) = static_cast<char_type>(ch);
            this->pbump(1);

            //2. 然后把放置区的数据输出给管道
            if(this->WriteImpl())
            {
                return ch;
            }
        }
    }

    return traits_type::eof();
}
 
template<class CharT, class Traits>
int PosixPipeBuf<CharT, Traits>::sync()
{
    if(this->WriteImpl())
        return 0;
    else
        return -1;
}


template<class CharT, class Traits>
typename PosixPipeBuf<CharT, Traits>::int_type PosixPipeBuf<CharT, Traits>::underflow()
{
    if(!m_stPipe.IsOpened())
        return traits_type::eof();

    if(this->egptr() == &m_stReadBuf.back())
    {
        // 到底了
        this->setg(m_stReadBuf.data(), m_stReadBuf.data() + 10, m_stReadBuf.data() + 10);
    }

    auto len = &m_stReadBuf.back() - this->egptr(); //可用的容量
    auto res = m_stPipe.Read(this->egptr(), static_cast<size_t>(len));  //从管道里读 写到获取区(添加在底部)


    if(res == 0)
    {
        // eof
        return traits_type::eof();
    }

    this->setg(this->eback(), this->gptr(), this->egptr() + res);
    auto val = *(this->gptr());

    return traits_type::to_int_type(val);
}


// read流
template<class CharT, class Traits>
PosixPipeistream<CharT, Traits>::PosixPipeistream():
    std::basic_istream<CharT, Traits>(nullptr)
{
    std::basic_istream<CharT, Traits>::rdbuf(&m_stBuf);
}

// write流
template<class CharT, class Traits>
PosixPipeostream<CharT, Traits>::PosixPipeostream():
    std::basic_ostream<CharT, Traits>(nullptr)
{
    std::basic_ostream<CharT, Traits>::rdbuf(&m_stBuf);
}


// read write流
template<class CharT, class Traits>
PosixPipeiostream<CharT, Traits>::PosixPipeiostream():
    std::basic_iostream<CharT, Traits>(nullptr)
{
    std::basic_iostream<CharT, Traits>::rdbuf(&m_stBuf);
}



}}


