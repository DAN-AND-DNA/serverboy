#include <ServerBoy.h>

#include <iostream>
#include <sstream>
#include <string>

namespace
{
    uint64_t dwUidBase = 1000;
}

namespace dan
{
namespace proxy
{

//int ServerBoy::ReadPipeFds[2] = {-1};
//int ServerBoy::WritePipeFds[2] = {-1};

dan::pipe::PosixPipeistream<char> ServerBoy::stOut;
dan::pipe::PosixPipeostream<char> ServerBoy::stIn;

ServerBoy::ServerBoy() noexcept:
    m_stHub(),
    m_ptrProxyGroup(m_stHub.createGroup<uWS::SERVER>()),
    m_stProxyMap()
{        

    //1. error handle
    m_ptrProxyGroup->onError([](int iPort){
            ::printf("ERROR: Connection\n");
    });

    //2. connection handle
    m_ptrProxyGroup->onConnection([this](uWS::WebSocket<uWS::SERVER>* pstWs, uWS::HttpRequest stReq){
            if(pstWs != nullptr)
            {
                ::dwUidBase++;
                //m_stProxyMap.emplace(::dwUidBase, pstWs);
                m_stProxyMap[::dwUidBase] = pstWs;
                ::printf("new conn, uid:%lu\n", ::dwUidBase);
                uint64_t* pstUid = new uint64_t(::dwUidBase);
                pstWs->setUserData(static_cast<void*>(pstUid));
                m_stProxyMap[::dwUidBase]->send(std::to_string(dwUidBase).c_str());
            }
            else
            {
                ::printf("ERROR: conn ptr is null\n");
            }
    });

    //3. disconnection
    m_ptrProxyGroup->onDisconnection([this](uWS::WebSocket<uWS::SERVER>* pstWs, int iCode, char* szMessage, size_t lLength){
            if(iCode == 1000)
            {
                printf("conn ip:%s is closing, code is correct\n", (pstWs->getAddress()).address);
            }
            else
            {
                printf("ERROR: conn is closing but code is %d\n", iCode);
            }
            auto ptrUid = static_cast<uint64_t*>(pstWs->getUserData());
            m_stProxyMap.erase(*ptrUid);
            if(ptrUid != nullptr)
            {
                delete ptrUid;
                ptrUid = nullptr;
            }
    });


    //4. msg handle
    m_ptrProxyGroup->onMessage([this](uWS::WebSocket<uWS::SERVER>* pstWs, char* szMessage, size_t lLength, uWS::OpCode opCode){
            //字符
            std::string message(szMessage, lLength);

            auto ptrUid = static_cast<uint64_t*>(pstWs->getUserData()); 
            message.append(",uid:");
            message.append(std::to_string(*ptrUid));

            //message.append("\n");   // for shell

            auto now = std::chrono::high_resolution_clock::now();
        
    //        printf("message:%s\n", message.c_str());
            ServerBoy::stIn << message << std::endl;

            /*
            if(::write(ServerBoy::ReadPipeFds[1], message.c_str(), message.size()) == -1)
            {
                printf("ERROR: on mse %s\n", ::strerror(errno));
            }
            */

            
           // char buffer[128];
            //auto i = ::read(ServerBoy::WritePipeFds[0], buffer, 128);

            std::string strEchoMsg;
            stOut >> strEchoMsg;
            //std::getline(stOut, strEchoMsg);

           // printf("read:%s\n", strEchoMsg.c_str());
            if(strEchoMsg == "")
            {
                printf("error\n");
            }
            else
            {
             //   std::string strEchoMsg(buffer, i);
                char* szServerMsg = std::strtok(const_cast<char*>(strEchoMsg.c_str()), "|");
                char* szClientMsg;
                std::vector<std::string> v;
                if(szServerMsg != NULL)
                {
                    szClientMsg = std::strtok(NULL , "|");
                }
               
                std::string ss(szServerMsg);
                std::istringstream iss(ss);
                for(std::string temp; getline(iss, temp, ',');) 
                {
                     v.push_back(temp);
                }

                if(v[0] == "0")
                {
                    // normal;
                    std::cout<<szClientMsg<<std::endl;
                    pstWs->send(szClientMsg);
                }
                else if(v[0] == "1")
                {
                    if(m_stProxyMap[atoi(v[1].c_str())] != nullptr)
                        m_stProxyMap[atoi(v[1].c_str())]->send(szClientMsg);
                }
                else{
                    std::cout<<"unknow msg\n";
                }

                int us = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - now).count();
                std::cout <<" cosume "<<double(us) <<" us"<< std::endl;
                //pstWs->send(strEchoMsg.c_str(), strEchoMsg.size(), uWS::OpCode::TEXT);
            }
    });
}

void ServerBoy::Run()
{
    if(!this->m_ptrProxyGroup)
        return;

    //TODO 读配置
    if(m_stHub.listen(7737, nullptr, 0, m_ptrProxyGroup.get()))
    {
        printf("server is listening to 7737\n");
    }

    m_stHub.run();
}

}
}


