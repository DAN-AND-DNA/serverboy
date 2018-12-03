#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <string>
#include <iostream>

using namespace std;

class Server {
public:
	Server(int port);
	~Server();

	void run();

private:
	void create();
	void close_socket();
	void serve();
	void handle(int);
	string get_request(int);
	bool send_response(int, string);

	int port_;
	int server_;
	int buflen_;
	char* buf_;
};
