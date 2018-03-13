#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<winsock2.h>
#include <string>
#pragma comment(lib,"ws2_32.lib") //Winsock Library

#define SERVER "127.0.0.1"  //ip address of udp server
#define BUFLEN 512  //Max length of buffer
#define PORT 12345   //The port on which to listen for incoming data

class Client
{
public:
	Client();
	~Client();
	int func();
	void Init();
	void Send(std::string);
private:
	struct sockaddr_in si_other;
	int s, slen;
	char buf[BUFLEN];
	char message[BUFLEN];
	WSADATA wsa;
};

