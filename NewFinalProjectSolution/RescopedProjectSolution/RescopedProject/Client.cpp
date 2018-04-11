#include "Client.h"

struct Client::MessageStruct {
	int messageID;
	std::string message;
	clock_t startTime;
};

void Client::Reciever()
{
	messageToSend = "Connect";
	CheckNewMessage();
	while (1)
	{
		//receive a reply and print it
		//clear the buffer by filling null, it might have previously received data
		memset(buf, '\0', BUFLEN);
		//try to receive some data, this is a blocking call
		int recieveInt = recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen);
		if (recieveInt == SOCKET_ERROR)
		{
			printf("Client recvfrom() failed with error code : %d", WSAGetLastError());
			system("PAUSE");
			//exit(EXIT_FAILURE);
		}
		if (buf[0] == 0) {
			continue;
		}
		printf("Client recieved: ");
		printf(buf);
		printf("\n\n");
		std::stringstream ss;
		ss << buf;
		std::string messageIntAsString;
		ss >> messageIntAsString;
		int messageInt = std::stoi(messageIntAsString.substr(0, messageIntAsString.find(',')));
		MessageStruct *itemToDelete = NULL;
		for each (MessageStruct *item in messageList)
		{
			if (item->messageID == messageInt) {
				clock_t endTime = clock();
				std::string newLine = std::to_string(item->messageID) + ","+ item->message +","+ std::to_string(endTime-item->startTime);
				file->PrintToFile(newLine);
				if (item->messageID > 100) {
					file->CloseFile();
					CloseProgram = true;
				}
				itemToDelete = item;
				break;
			}
		}
		if (itemToDelete != NULL) {
			messageList.remove(itemToDelete);
			itemToDelete = NULL;
		}
		delete(itemToDelete);
	}
	closesocket(s);
	WSACleanup();
	return;
}

void Client::Init() {
	CloseProgram = false;
	messageCount = 0;
	slen = sizeof(si_other);
	printf("Initialising Winsock for client...\n");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		system("PAUSE");
		exit(EXIT_FAILURE);
	}
	printf("Initialised Winsock on Client.\n");

	//create socket
	if ((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == SOCKET_ERROR)
	{
		printf("socket() failed with error code : %d", WSAGetLastError());
		system("PAUSE");
		exit(EXIT_FAILURE);
	}

	memset((char *)&si_other, 0, sizeof(si_other));
	si_other.sin_family = AF_INET;
	si_other.sin_port = htons(PORT);
	si_other.sin_addr.S_un.S_addr = inet_addr(SERVER);
	memset(message, '\0', BUFLEN);
	//start communication
	messageToSend = "";
	file = new File();
	file->init();
}

void Client::CheckNewMessage() {
	if (messageToSend != "") {
		MessageStruct *newMessage = new MessageStruct();
		newMessage->messageID = messageCount++;
		newMessage->message = messageToSend;
		newMessage->startTime = clock();
		messageList.push_back(newMessage);
		messageToSend = "";
	}
	if (messageList.size() > 0) {
		SendList();
	}
}

void Client::SendList() {
	try {
		for each (MessageStruct *currentItem in messageList)
		{
			std::string sendThis = std::to_string(currentItem->messageID) + "," + currentItem->message;
			strcpy(message, sendThis.c_str());
			if (sendto(s, message, strlen(message), 0, (struct sockaddr *) &si_other, slen) == SOCKET_ERROR)
			{
				printf("sendto() failed with error code : %d", WSAGetLastError());
				system("PAUSE");
				exit(EXIT_FAILURE);
			}
		}
	}
	catch(const std::out_of_range& e){
		printf("ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	}
}

void Client::AmmendMessage(std::string addition) {
	messageToSend += addition;
}

Client::Client()
{
}

Client::~Client()
{
}