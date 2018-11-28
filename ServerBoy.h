#pragma once

#include <uWS/uWS.h>
#include <pipe/PosixPipe.hpp>
#include <memory>
#include <unordered_map>

namespace dan
{
namespace proxy
{

class ServerBoy
{
public:
    ServerBoy() noexcept;
    void Run();

public:
    static dan::pipe::PosixPipeistream<char> stOut;
    static dan::pipe::PosixPipeostream<char> stIn;
    //static int ReadPipeFds[2];  //从ServerBoy读消息
    //static int WritePipeFds[2]; //往ServerBoy写消息

private:
    uWS::Hub m_stHub;
    std::unique_ptr<uWS::Group<uWS::SERVER>> m_ptrProxyGroup;
    std::unordered_map<uint64_t, uWS::WebSocket<uWS::SERVER>*> m_stProxyMap;  //  {每个连接的uid , 连接的指针}
    std::vector<uint64_t> m_Uids;
};


}
}



