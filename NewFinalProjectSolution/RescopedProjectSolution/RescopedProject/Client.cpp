#include "Client.h"

struct Client::MessageStruct {
	int messageID;
	std::string message;
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
		int i = recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen);
		if (recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen) == SOCKET_ERROR)
		{
			printf("Client recvfrom() failed with error code : %d", WSAGetLastError());
			system("PAUSE");
			//exit(EXIT_FAILURE);
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
				itemToDelete = item;
				break;
			}
		}
		if (itemToDelete != NULL) {
			messageList.remove(itemToDelete);
			itemToDelete = NULL;
			delete(itemToDelete);
		}
	}

	closesocket(s);
	WSACleanup();

	return;
}

void Client::Init() {
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
}


void Client::CheckNewMessage() {
	if (messageToSend != "") {
		MessageStruct *newMessage = new MessageStruct();
		newMessage->messageID = messageCount++;
		newMessage->message = messageToSend;
		messageList.push_back(newMessage);
		messageToSend = "";
	}
	if (messageList.size() > 0)
		SendList();
}

void Client::SendList() {
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

void Client::AmmendMessage(std::string addition) {
	messageToSend += addition;
}


Client::Client()
{
}

Client::~Client()
{
}

