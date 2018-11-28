#pragma once

#include <exception>
#include <string>

// FIXME  stack地址变成行如: addr2line -e Exception_test 0x401569
// TODO  stack可以在捕捉信号SIGSEGV 即非法内存时使用
// 
namespace dan
{
class Exception : public std::exception
{
public:
    Exception(const char* szMessage);
    Exception(const std::string& strMessage);
    virtual ~Exception() throw();
    virtual const char* what()const throw();            // 异常消息
    const char* StackTrace()const throw();              // 拿调用栈

private:
    void FillStackTrace();                              // 补充调用栈消息
private:
    std::string m_strMessage_;
    std::string m_strStack_;
};

}


