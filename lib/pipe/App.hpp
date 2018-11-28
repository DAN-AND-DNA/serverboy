#pragma once

#include <istream>
#include <ostream>
#include <pipe/PosixPipe.hpp>
#include <sys/wait.h>
#include <memory>
#include <atomic>
#include <iostream>

namespace dan { namespace app {

class PipeIn
{
public:
    PipeIn() = default;
    PipeIn(const PipeIn& in) = default;
    PipeIn(PipeIn&& in) = default;

    template<typename T>
    PipeIn(T& p):m_iEndPoint0(p.EndPoint0()),m_iEndPoint1(p.EndPoint1()){}

    void PreExec();
private:
    int m_iEndPoint0;
    int m_iEndPoint1;
};

class PipeOut
{
public:
    PipeOut() = default;
    PipeOut(const PipeOut& out) = default;
    PipeOut(PipeOut&& out) = default;
    
    template<typename T>
    PipeOut(T& p):m_iEndPoint0(p.EndPoint0()),m_iEndPoint1(p.EndPoint1()){}

    void PreExec();
private:
    int m_iEndPoint0;
    int m_iEndPoint1;
};



// 0 out
class AppOut
{
public:
    template<class CharT, class Traits> 
    PipeOut operator > (dan::pipe::PosixPipeistream<CharT, Traits> & out) const;
};


// in
class AppIn
{
public:
    template<class CharT, class Traits> 
    PipeIn operator < (dan::pipe::PosixPipeostream<CharT, Traits> & in) const;
private:

};






class App
{
public:
    App() = delete;
    App(const char* pstExe, PipeOut stPipeOut, PipeIn stPipIn) noexcept;
   // App(const char* pstExe, char* const* pstArgs, PipeOut stPipeOut, PipeIn stPipIn);
    void Wait(int & stExitCode) noexcept;
    ::pid_t Pid(){return m_stPid;}
    int ExitCode(){return m_pstExitCode->load();}
    std::string StrError() {return ::strerror(m_pstErrorCode->load());}
    bool Running() noexcept;
private:
    const char* m_szExe;
    char* const* m_pstArgs;
    PipeOut m_stPipeOut;
    PipeIn m_stPipeIn;
    ::pid_t m_stPid;
//    std::string m_strError;
    std::shared_ptr<std::atomic<int>> m_pstExitCode;
    std::shared_ptr<std::atomic<int>> m_pstErrorCode;
};





//
//
//
//
//
bool App::Running() noexcept
{
    if(m_stPid == -1)
    {
        return false;
    }

    int iStatus = 0;
    ::pid_t res = ::waitpid(m_stPid, &iStatus, WNOHANG);

    switch(res)
    {
        case -1:
        {
            //m_strError = std::move(::strerror(errno));
            return false;
        }
        case 0:
        {
            //if()
            return true;
        }
        default:
        {
            if(WIFEXITED(iStatus) || WIFSIGNALED(iStatus))
            {
                // stop
                m_pstExitCode->store(iStatus);
            }
            return false;
        }
    }
}


void App::Wait(int& stExitCode) noexcept
{
    ::pid_t ret = 0;
    int iStatus = 0;

    do
    {
       ret = ::waitpid(m_stPid, &iStatus, 0);
    }
    while((ret == -1 && errno == EINTR) || (ret != -1 && !WIFEXITED(iStatus) && !WIFSIGNALED(iStatus)));
    
    if(ret == -1)
    {
        //m_strError = std::move(::strerror(errno));
        m_pstErrorCode->store(errno);
    }
    else
    {
        m_pstExitCode->store(iStatus);
        stExitCode = iStatus;
    }
}


void PipeOut::PreExec()
{
    if(::dup2(m_iEndPoint1, STDOUT_FILENO) == -1)
    {
        //TODO 
    }

    ::close(m_iEndPoint1);
  //  ::setbuf(stdout, NULL);
   // ::close(m_iEndPoint0);
}

void PipeIn::PreExec()
{
    if(::dup2(m_iEndPoint0, STDIN_FILENO) == -1)
    {
        //TODO 
    }

    ::close(m_iEndPoint0);
    //::setbuf(stdin, NULL);
    //::close(m_iEndPoint1);
}




App::App(const char* pstExe, PipeOut stPipeOut, PipeIn stPipeIn) noexcept:
    m_szExe(std::move(pstExe)),
    m_pstArgs(nullptr),
    m_stPipeOut(std::move(stPipeOut)),
    m_stPipeIn(std::move(stPipeIn)),
    m_stPid(-1),
   // m_strError("ok"),
    m_pstExitCode(std::make_shared<std::atomic<int>>(0)),
    m_pstErrorCode(std::make_shared<std::atomic<int>>(0))
{
    //
    m_stPid = ::fork();
    if(m_stPid == -1)
    {
        //TODO 设置错误
    }
    else if(m_stPid == 0)
    {
        // in app
        m_stPipeOut.PreExec();
        m_stPipeIn.PreExec();

        if(::execv(m_szExe, m_pstArgs) == -1)
        {
            m_pstErrorCode->store(errno);
            std::cout<<std::endl;
            //std::cout<<"error"<<std::endl;
            //printf("%s\n", "error");
           // m_strError = std::move(::strerror(errno));
            //printf("%s\n", m_strError.c_str());
        }

        //::exit(7);
        //printf("jjj\n");
        //TODO 设置错误
        ::_exit(EXIT_FAILURE);
    }
    std::cout<<"loading app..."<<std::endl;
    sleep(3);
    // in parent
}
/*
App::App(const char* pstExe, char* const* pstArgs, PipeOut stPipeOut, PipeIn stPipeIn):
    m_stPipeOut(std::move(stPipeOut)),
    m_stPipeIn(std::move(stPipeIn))
{}
*/

template<class CharT, class Traits> 
PipeOut AppOut::operator > (dan::pipe::PosixPipeistream<CharT, Traits> & out) const
{
   return out.Pipe(); 
}


    
template<class CharT, class Traits> 
PipeIn AppIn::operator < (dan::pipe::PosixPipeostream<CharT, Traits> & in) const
{
   return in.Pipe(); 
}


// 全局
constexpr AppIn appin;
constexpr AppOut appout;

}}


