#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include "server.h"

using namespace std;

int main(int argc, char** argv)
{
	int option, port;

	port = 30000;

	// see "man 3 getopt"
	while ((option = getopt(argc, argv, "p:")) != -1) {
		switch (option) {
			case 'p':
				port = atoi(optarg);
				break;
			default:
				cout << "server [-p port]" << endl;
				exit(EXIT_FAILURE);
		}
	}

	Server server = Server(port);
	server.run();
}
