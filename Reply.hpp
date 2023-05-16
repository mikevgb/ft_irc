#ifndef REPLY_HPP
#define REPLY_HPP

#include <iostream>
#include <string>
#include "Message.hpp"

class Reply : public Message
{
private:
	int code;

public:
	// Constructors
	Reply();
	Reply(int code);
	Reply(const Reply &copy);

	// Destructor
	~Reply();

	// Operators
	Reply &operator=(const Reply &assign);

	//Getters and Setters
	int getCode() const;
	void setCode(const int code);
};

#endif
