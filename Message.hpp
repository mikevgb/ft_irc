#ifndef MESSAGE_H
#define MESSAGE_H
#include <cstring>
#include "User.hpp"
class Message
{
private:
	int _fd;
	std::string _msg;

public:
	Message(int fd, std::string msg);
	~Message();
};

Message::Message(int fd, std::string msg)
	: _fd(), _msg()
{
}

Message::~Message()
{
}

#endif
