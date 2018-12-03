#include "server.h"

Server::Server(int port) {
	// setup variables
	port_ = port;
	buflen_ = 1024;
	buf_ = new char[buflen_+1];
}

Server::~Server() {
	delete[] buf_;
}

void Server::run() {
	// create and run the server
	create();
	serve();
}

void Server::create() {
	struct sockaddr_in server_addr;

	// setup address structure
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port_);
	server_addr.sin_addr.s_addr = INADDR_ANY;

	// create socket
	server_ = socket(PF_INET, SOCK_STREAM, 0);
	if(!server_) {
		perror("socket");
		exit(-1);
	}

	int reuse = 1;
	if(setsockopt(server_, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0) {
		perror("setsockopt");
		exit(-1);
	}

	if(bind(server_, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
		perror("bind");
		exit(-1);
	}

	if(listen(server_, SOMAXCONN) < 0) {
		perror("listen");
		exit(-1);
	}
}

void Server::close_socket() {
	close(server_);
}

void Server::serve() {
	// setup client
	int client;
	struct sockaddr_in client_addr;
	socklen_t clientlen = sizeof(client_addr);

	while((client = accept(server_, (struct sockaddr *)&client_addr, &clientlen)) >0) {
		handle(client);
	}
		
	close_socket();
}

void Server::handle(int client) {
	while(true){
		cout << "hello, handle";
		string request = get_request(client);
		if(request.empty())
			break;
		bool success = send_response(client, request);
		if(not success)
			break;
	}
	close(client);
}

string Server::get_request(int client) {
	string request = "";

	while(request.find("\n") == string::npos) {
		int nread = recv(client, buf_, 1024, 0);
		if (nread < 0) {
			if(errno == EINTR)
				continue;
			else
				return "";
		}
		else if (nread == 0) {
			return "";
		}
		request.append(buf_, nread);
	}
	return request;
}

bool Server::send_response(int client, string response) {
	const char* ptr = response.c_str();
	int nleft = response.length();
	int nwritten {};

	while(nleft){
		if((nwritten = send(client, ptr, nleft, 0)) < 0) {
			if(errno == EINTR) {
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
