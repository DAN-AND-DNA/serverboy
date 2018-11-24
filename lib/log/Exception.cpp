#include <log/Exception.h>
#include <execinfo.h>

namespace dan
{

Exception::Exception(const char* szMessage):
    m_strMessage_(szMessage)
{
    FillStackTrace();
}

Exception::Exception(const std::string& strMessage):
    m_strMessage_(strMessage)
{
    FillStackTrace();
}

Exception::~Exception() throw()
{}

const char* Exception::what() const throw()
{
    return m_strMessage_.c_str();
}

const char* Exception::StackTrace() const throw()
{
    return m_strStack_.c_str();
}

void Exception::FillStackTrace()
{
    const int iLen = 200;
    void * pvBuffer[iLen];      //指针数组
    int iNptrs = ::backtrace(pvBuffer, iLen);
    char** pszStrings = ::backtrace_symbols(pvBuffer, iNptrs);
    if(pszStrings)
    {
        for(int i = 0; i < iNptrs; ++i)
        {
            m_strStack_.append(pszStrings[i]);
            m_strStack_.push_back('\n');
        }

        ::free(pszStrings);
    }
}


}
