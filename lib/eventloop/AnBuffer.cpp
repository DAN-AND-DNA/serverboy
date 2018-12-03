#include <eventloop/AnBuffer.h>

namespace dan { namespace eventloop {

AnBuffer::AnBuffer(size_type ulMaxLimit):
    m_stBackBuffer(2048),
    m_stMaxLimit(ulMaxLimit),
    m_stReadIndex(0),
    m_stWriteIndex(0)
{}

AnBuffer::~AnBuffer()
{}

uint8_t* AnBuffer::WritePtr()
{
    return &(m_stBackBuffer[m_stWriteIndex]);
}

uint8_t* AnBuffer::ReadPtr()
{
    return &(m_stBackBuffer[m_stReadIndex]);;
}

uint8_t* AnBuffer::BeginPtr()
{
    return m_stBackBuffer.data();
}

void AnBuffer::SetReadIndex(size_type stIndex)
{
    m_stReadIndex = stIndex;
}

void AnBuffer::SetWriteIndex(size_type stIndex)
{
    m_stWriteIndex = stIndex;
}

bool AnBuffer::MakeSpace()
{
    if(m_stBackBuffer.size() >= m_stMaxLimit)
    {
        return false;
    }

    if(m_stBackBuffer.size() * 2 > m_stMaxLimit)
    {
        m_stBackBuffer.resize(m_stMaxLimit);
    }
    else
    {
        m_stBackBuffer.resize(m_stBackBuffer.size() * 2);
    }

    return true;
}



}}
