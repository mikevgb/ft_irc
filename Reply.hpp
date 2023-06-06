#ifndef REPLY_HPP
#define REPLY_HPP

#include <iostream>
#include <string>
#include <set>
#include "User.hpp"
#include "Message.hpp"
#include "NumericalReplies.hpp"

class Reply : public Message
{
private:
	int _code;
	std::set<int> _targets;

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
	std::set<int> getTargets() const;
	void setCode(const int code);
	void addTarget(const int & fd);
	std::string getReplyMsg(std::string hostname) const;
	void setReplyMsg(const int code, const std::string message);
};

#endif
