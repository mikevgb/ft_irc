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
	std::string _code;
	std::set<int> _targets;

public:
	// Constructors
	Reply();
	Reply(const std::string code);
	Reply(const Reply &copy);

	// Destructor
	~Reply();

	// Operators
	Reply &operator=(const Reply &assign);

	//Getters and Setters
	std::string getCode() const;
	std::set<int> getTargets() const;
	void setCode(const std::string code);
	void addTarget(const int & fd);
	std::string getReplyMsg(const std::string hostname, std::string nick) const;
	void setReplyMsg(const std::string code, const std::string message);
};

#endif
