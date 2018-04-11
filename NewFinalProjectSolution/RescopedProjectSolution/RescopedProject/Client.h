#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<winsock2.h>
#include <string>
#pragma comment(lib,"ws2_32.lib") //Winsock Library
#include <thread>
#include <list>
#include <sstream>
#include "File.h"

#define SERVER "86.128.96.225"  //ip address of udp server
#define BUFLEN 512  //Max length of buffer
#define PORT 12345   //The port on which to listen for incoming data

class Client
{
public:
	Client();
	~Client();
	void Reciever();
	void Init();
	void CheckNewMessage();
	void AmmendMessage(std::string);
	bool CloseProgram;
private:
	
	struct sockaddr_in si_other;
	int s, slen;
	char buf[BUFLEN];
	char message[BUFLEN];
	std::string messageToSend;
	WSADATA wsa;
	int messageCount;
	struct MessageStruct;
	std::list<MessageStruct*> messageList;
	void SendList();
	File *file;
};

