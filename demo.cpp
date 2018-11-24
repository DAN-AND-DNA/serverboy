#include <iostream>
#include <string>
#include <string.h>
#include <unistd.h>
#include <sstream>
#include <map>
#include <cstring>
#include <memory>

namespace
{


}


void TestEcho()
{
    /*
        while(true)
            {
                std::string strIn;
                std::cin >> strIn;
                std::cout<<strIn<<std::endl;
            }
    */

    // faster
    ::setbuf(stdin, NULL);
    ::setbuf(stdout, NULL);
    
    while(true)
    {
        char buf[40];
        ::bzero(buf, sizeof(buf));
        ::read(STDIN_FILENO, buf, sizeof(buf));
        printf("%s\n", buf);
    }

}


inline std::string& trim(std::string& text)
{
    if(!text.empty())
    {
        text.erase(0, text.find_first_not_of((" \n\r\t")));
        text.erase(text.find_last_not_of((" \n\r\t")) + 1);
    }
    return text;
}


inline void split(const std::string& s, std::map<std::string, std::string>& m, const char flag = ',') {
    m.clear();
    std::istringstream iss(s);
    std::string temp;

    while (getline(iss, temp, flag)) 
    {
        char* key = std::strtok(const_cast<char*>(temp.c_str()), ":");
        
        while(key != NULL)
        {
            char* value = std::strtok(NULL , ":");
            m[key]= value;
            key = NULL;
        }
    }
}


inline void TestRoute()
{
    ::setbuf(stdin, NULL);
    ::setbuf(stdout, NULL);
    
    std::string strMsg;
    std::map<std::string, std::string> m;
    while(true)
    {
        std::cin>>strMsg;

        if(!strMsg.empty())
        {
            split(strMsg, m);
        }

        //解析msg
        if(m["msg"] == "makeroom")
        {
            //正常
            std::cout<<"0 {res:0}";
        }
        else if(m["msg"] == "broadcast_move")
        {
            //广播
            std::cout<<"1,1001,1002 {x:"<<m["x"]<<",y:"<<m["y"]<<",roomer:2000}";
        }
        else
        {   //未知
            std::cout<<"0 {res:-1}";
        }
    }
}


void TestGameDemo()
{
    ::setbuf(stdin, NULL);
    ::setbuf(stdout, NULL);


    std::string strMsg;
    std::map<std::string, std::string> m;

    class player
    {
        public:
            player(){}
        private:
            int hp;
            std::string x;
            std::string y;
    };

    using room = std::map<std::string, std::unique_ptr<player>>; // uid, player
    std::map<uint64_t, room> roomlist;   //roomid, room
    uint64_t roomid = 3000;

    while(true)
    {
        std::cin>>strMsg;

        if(!strMsg.empty())
        {
            split(strMsg, m);
        }

        //解析msg
        if(m["msg"] == "makeroom")
        {
            roomid ++;
            (roomlist[roomid])[m["uid"]] = std::unique_ptr<player>(new player);

            //一般的消息
            std::cout<<"0 {res:0,roomid:"<<roomid<<"}";
        }
        else if(m["msg"] == "roomlist")
        {
            std::string strRoomlist("0 {res:0,roomlist:[");
            for (const auto& p : roomlist)
            {
                strRoomlist.append(",");
                strRoomlist.append(std::to_string(p.first));

            }

            strRoomlist.append("]}");
            std::cout<<strRoomlist;

        }
        else if(m["msg"] == "broadcast_move")
        {
            //广播类的消息
            if(m["uid"] == "1001")
                std::cout<<"1,1002 {\"x\":"<<m["x"]<<",\"y\":"<<m["y"]<<"}";

            if(m["uid"] == "1002")
                std::cout<<"1,1001 {\"x\":"<<m["x"]<<",\"y\":"<<m["y"]<<"}";
        }
        else if(m["msg"] == "joinroom")
        {

        }
        else
        {   //未知
            std::cout<<"0 {res:-1}";
        }
    }


}


int main()
{
    //TestEcho();
//    TestRoute();
    TestGameDemo();
}
