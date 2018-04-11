#include "File.h"

File::File()
{
}

File::~File()
{
}

void File::init() {
	file = new std::ofstream();
	file->open("outputFile.csv");
	*file << "MessageID,Message,Latency\n";
}

void File::PrintToFile(std::string line){
	*file << (line + "\n");
}

void File::CloseFile() {
	file->close();
}
