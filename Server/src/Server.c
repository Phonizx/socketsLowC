/*
 ============================================================================
 Name        : Server.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#if defined WIN32
#include <winsock.h>
#else
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#define closesocket close
#endif

#include <stdio.h>
#include <stdlib.h>
#include "Network.h"
//...

int main(int argc, char *argv[]) {
	//...
#if defined WIN32
	// Initialize Winsock
	WSADATA wsa_data;
	int result = WSAStartup(MAKEWORD(2, 2), &wsa_data);
	if (result != 0) {
		printf("Error at WSAStartup()\n");
		return 0;
	}
#endif
	serverListen(1);
	//...
	printf("Server online.\n");

#if defined WIN32
	system("PAUSE");
#else
	getchar();
#endif

	//closesocket(my_socket);

	return 0;
} // main end
