#pragma once
#include <string>
class Server
{
public:
	Server();
	~Server();
	int StartServer();
private:
	std::string returnMessageCount(std::string);
};

