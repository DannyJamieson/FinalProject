#pragma once
#include <string>
class Server
{
public:
	Server();
	~Server();
	int func();
private:
	std::string returnMessageCount(std::string);
};

