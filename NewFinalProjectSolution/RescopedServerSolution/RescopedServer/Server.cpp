#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "Server.h"
#include<stdio.h>
#include<winsock2.h>


//Error	C4996	'inet_ntoa': Use inet_ntop() or InetNtop() instead or define _WINSOCK_DEPRECATED_NO_WARNINGS to disable deprecated API warnings	RescopedProject	c : \users\daniel\desktop\github\finalproject\newfinalprojectsolution\rescopedprojectsolution\rescopedproject\server.cpp	69



#pragma comment(lib,"ws2_32.lib") //Winsock Library

#define BUFLEN 512  //Max length of buffer
#define PORT 12345   //The port on which to listen for incoming data



int Server::StartServer() {
	SOCKET s;
	struct sockaddr_in server, si_other;
	int slen, recv_len;
	char buf[BUFLEN];
	WSADATA wsa;

	slen = sizeof(si_other);

	//Initialise winsock
	printf("Server Initialising Winsock...\n");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("Server Failed. Error Code : %d", WSAGetLastError());
		system("PAUSE");
		exit(EXIT_FAILURE);
	}
	printf("Initialised.\n");

	//Create a socket
	if ((s = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET)
	{
		printf("Server Could not create socket : %d", WSAGetLastError());
	}
	printf("Server Socket created.\n");

	//Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(PORT);

	//Bind
	if (bind(s, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR)
	{
		printf("Server Bind failed with error code : %d", WSAGetLastError());
		system("PAUSE");
		exit(EXIT_FAILURE);
	}
	puts("Bind done\n");

	//keep listening for data
	while (1)
	{
		fflush(stdout);
		//clear the buffer by filling null, it might have previously received data
		memset(buf, '\0', BUFLEN);

		//try to receive some data, this is a blocking call
		if ((recv_len = recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen)) == SOCKET_ERROR)
		{
			printf("Server recvfrom() failed with error code : %d", WSAGetLastError());
			system("PAUSE"); 
			exit(EXIT_FAILURE);
		}

		//print details of the client/peer and the data received
		//printf("Server received packet from %s:%d\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port));
		printf("Server data: %s\n", buf);
		std::string returnMessage = returnMessageCount(buf) + " ACK";
		//now reply the client with the same data
		if (sendto(s, returnMessage.c_str(), recv_len, 0, (struct sockaddr*) &si_other, slen) == SOCKET_ERROR)
		{
			printf("Server sendto() failed with error code : %d", WSAGetLastError());
			system("PAUSE");
			exit(EXIT_FAILURE);
		}
		std::string printString = "Server sent: " + returnMessage + "\n";
		printf(printString.c_str());
		printf("\n");
	}

	closesocket(s);
	WSACleanup();
	return 0;
}

std::string Server::returnMessageCount(std::string inputMessage) {
	return inputMessage.substr(0, inputMessage.find(','));
}

Server::Server()
{
}

Server::~Server()
{
}
