#pragma once

#include <vector>
#include <stdint.h>
//#include <cstdio>


namespace dan { namespace eventloop {
//
// swap double buffer
//  
class AnBuffer
{
public:
    using size_type = std::vector<uint8_t>::size_type;

    AnBuffer  (size_type ulMaxLimit);
    ~AnBuffer ();
    uint8_t*    WritePtr();
    uint8_t*    ReadPtr();
    uint8_t*    BeginPtr();

    size_type ReadIndex (){return m_stReadIndex;}
    size_type WriteIndex(){return m_stWriteIndex;}
    size_type Readable  (){return m_stWriteIndex - m_stReadIndex;}
    size_type Writeable (){return m_stBackBuffer.size() - m_stWriteIndex;}
    size_type Processed (){return m_stReadIndex;}
    size_type Size()      {return m_stBackBuffer.size();}
    size_type MaxLimit  (){return m_stMaxLimit;}
    bool      MakeSpace ();

    void SetReadIndex(size_type stIndex);
    void SetWriteIndex(size_type stIndex);
private:
    std::vector<uint8_t>  m_stBackBuffer;
    size_type             m_stMaxLimit;
    size_type             m_stReadIndex;
    size_type             m_stWriteIndex;
};

}}
