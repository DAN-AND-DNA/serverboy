#include "client.h"
//#include "proto/db.pb.h"
//#include "proto/api.pb.h"

Client::Client(string host, int port) {
	host_ = host;
	port_ = port;
	buflen_ = 1024;
	buf_ = new char[buflen_+1];
}

Client::~Client() {
	delete[] buf_;
}

void Client::run() {
	create();
	echo();
}

void Client::create() {
	struct sockaddr_in server_addr;

	struct hostent *hostEntry;
	hostEntry = gethostbyname(host_.c_str());
	if(!hostEntry) {
		cout << "No such host name: " << host_ <<endl;
		exit(-1);
	}

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port_);
	memcpy(&server_addr.sin_addr, hostEntry->h_addr_list[0], hostEntry->h_length);

	server_ = socket(PF_INET, SOCK_STREAM, 0);
	if(!server_) {
		perror("socket");
		exit(-1);
	}

	if(connect(server_,(const struct sockaddr* )&server_addr, sizeof(server_addr)) < 0) {
		perror("connect");
		exit(-1);
	}
}

void Client::close_socket() {
	close(server_);
}

void Client::echo() 
{
	string line;

	while(getline(cin,line)) 
        {
  //          api::login_q stLogin;
    //        stLogin.set_openid("dadadaaa7");
      //      uint32_t reLen=stLogin.ByteSize();
                 
        //    static uint8_t*reBuffer1=(uint8_t*)calloc(reLen,sizeof(uint8_t));
          //  static uint8_t*result1=(uint8_t*)calloc(reLen+6,sizeof(uint8_t));
                   
            
        /*    db::updateegg_q stQ;
            stQ.set_openid("wx1211qqq");
            stQ.set_eggs(7);
          */    
           // std::cout<<"byteSize:" << reLen<<std::endl;
           // reLen = 11;
            //static uint8_t*reBuffer=(uint8_t*)calloc(reLen,sizeof(uint8_t));
           // uint8_t*result=(uint8_t*)calloc(stQ.ByteSize()+6,sizeof(uint8_t));
           // static uint8_t*buffer=(uint8_t*)calloc(60,sizeof(uint8_t));


                if(line == "quit")
                    break;

                if(line == "send1")
                {
                
                    const char* szMsg = "echo20187777";
                    int n= ::send(server_, szMsg, ::strlen(szMsg) + 1, 0);

                    printf("send: %d\n", n);
                     char buffer[128] ={0};
                     auto i = ::recv(server_, buffer, 128, 0);


                    printf("%d   %s\n",i,buffer); 

            //        stLogin.SerializeToArray(reBuffer1,reLen);
              //      uint8_t*result1=(uint8_t*)calloc(stLogin.ByteSize()+6,sizeof(uint8_t));
 
                //    uint16_t reId = 257;
                   // uint16_t reId =1000;
                  //  memcpy(result1,(uint8_t*)&reId, 2);
                    //memcpy(result1+2, (uint8_t*)&reLen, 4);
                    //memcpy(result1+2+4,reBuffer1, reLen);
                    //int i = 6+ reLen;
                    //std::cout<<reLen<<std::endl;
                    //while(i)
                   // {
                     //   int n=::send(server_, result1, i, 0);
                       // i-=n;
                   // }
                   // free(result1);
                }
                
                if(line == "send2")
                {

                    for(int j=0; j<1; j++)
                    {
            /*            uint32_t reLen=stLogin.ByteSize();
 uint8_t*result=(uint8_t*)calloc(reLen+6,sizeof(uint8_t));
           

                     std::cout<< "send2 byteSize:" << reLen<<std::endl;

                     reLen = 11;
                    stLogin.SerializeToArray(reBuffer,reLen);

                    uint16_t reId = 257;
                    memcpy(result,(uint8_t*)&reId, 2);
                    memcpy(result+2, (uint8_t*)&reLen, 4);
                    memcpy(result+2+4,reBuffer, reLen);
                    int i = 6+ reLen;
                    std::cout<<reLen<<std::endl;
                    while(i)
                    {
                        int n=::send(server_, result, i, 0);
                        std::cout<<"n:"<<n<<std::endl;
                        i-=n;
                    }

                    std::cout<<"wait...recv...\n";
                    uint8_t*buffer=(uint8_t*)calloc(8,sizeof(uint8_t));
                    ::recv(server_, buffer, 8, 0);

                    std::cout<<"ok\n";
                    
                    //db::updateegg_r stR;
                    api::login_r stR;
                    int recvID = *((uint16_t*)buffer);
                    int recvLen = *((uint32_t*)(buffer+2));

                    std::cout<<"recv:"<<recvID<<" recvLen:"<<recvLen<<std::endl;
                    stR.ParseFromArray(buffer+6, recvLen);
                    free(buffer);
                    result = nullptr;
                    buffer = nullptr;
                    bool resultb = stR.result();

                    std::cout<<"get :"<<resultb<<std::endl;
                    
                     free(result);
                    ::sleep(1);
                    */
                    }
                    
                }


                if(line == "send3")
                {
                }
        }

	close_socket();
}

bool Client::send_request(string request) 
{

	const char* ptr = request.c_str();
	int nleft = request.length();
	int nwritten {};
	while(nleft) {
		if ((nwritten = send(server_, ptr, nleft, 0)) < 0) {
			if (errno == EINTR) {
				continue;
			} else {
				perror("write");
				return false;
			}
		} else if (nwritten == 0) {
			return false;
		}
		nleft -= nwritten;
		ptr += nwritten;
	}
	return true;
}

bool Client::get_response() {
	string response = "";

	while(response.find("\n") == string::npos) {
		int nread = recv(server_, buf_, 1024, 0);
		if (nread < 0) {
			if (errno == EINTR)
				continue;
			else
				return "";
		} else if (nread == 0) {
			return "";
		}

		response.append(buf_, nread);
	}
	
	cout << response;
	return true;
}
