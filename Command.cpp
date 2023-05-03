/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:43:47 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/05/03 12:45:29 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

/*
The function getToNext() in the Command class is used to get the next part
of a message in the format <command> <target1> <target2> :<message>. The
function uses the _temp string variable, which contains the remaining
message, to extract the next part of the message. The function first
checks if the remaining message starts with a colon (:), which indicates
that the remaining message is the last part of the message (i.e. the
message itself). If the remaining message does not start with a colon,
the function searches for the next space or colon character in the
remaining message and extracts the part of the message before that
character. If no space or colon character is found, the remaining
message is returned as is. The extracted part of the message is then
returned by the function, and the remaining message is updated to exclude
the extracted part.
*/

const std::string Command::getToNext()
{
	std::string result = std::string("");
	if (!_temp.empty() && _temp[0] == ':')
	{
		result = _temp;
		_temp = "";
		return result;
	}
	size_t pos = _temp.find_first_of(" ", 0);
	if (pos != std::string::npos)
	{
		result = _temp.substr(0, pos);
		if (_temp[pos] == ' ')
			_temp = _temp.substr(pos + 1);
		else
			_temp = _temp.substr(pos);
	}
	else
	{
		result = _temp;
		_temp = "";
	}
	return result;
}

/*
const std::string Command::getToNext()
{
	std::string result = std::string("");
	if(!_temp.empty() && _temp[0]==':')
	{
		result = _temp;
		_temp = "";
		return result;
	}
	size_t pos;
	size_t pos1 = _temp.find_first_of(" ", 0);
	size_t pos2 = _temp.find_first_of(":", 0);
	pos2 = pos2 == 0 ? std::string::npos : pos2;
	if (pos1 != std::string::npos && pos2 != std::string::npos)
		pos = pos1 < pos2 ? pos1 : pos2;
	else if (pos1 != std::string::npos)
		pos = pos1;
	else
		pos = pos2;
	if (pos != std::string::npos)
	{
		result = _temp.substr(0, pos);
		if(_temp[pos] == ' ')
			_temp = _temp.substr(pos + 1);
		else
			_temp = _temp.substr(pos);
	} else {
		result = _temp;
		_temp = "";
	}
	return result;
}
*/

/*
This constructor takes in two parameters: from, an int representing the sender
of the command, and msg, a std::string representing the message of the
command. The constructor initializes the _msg member variable with the
msg parameter. It then performs some operations on the _temp member variable,
which seems to be a temporary string used for storing the msg parameter.

Next, the constructor checks if the first character of _temp is a
colon (':'), and if so, it sets the _cmd member variable to the next element
in _temp. It then sets _cmd to the next element in _temp regardless of
whether or not the first character of _temp was a colon.

The constructor then enters a loop that iterates over the elements in _temp
until it is empty. For each element, it calls the getToNext() function,
which returns the next element in _temp, and adds it to the _params queue.
If _temp is not empty after the loop, it adds its remaining value to the
_params queue as well.

The constructor then sets the _cmd member variable to the lowercase version
of itself using the setCommand() function. Finally, it generates the targets
of the command by calling the generateTargets() function, which returns an
int indicating the number of targets generated.
*/

Command::Command(int from, const std::string &msg)
	: _from(from), _msg(msg), _cmd(), _params()
{
	_msg = msg;
	try
	{
		_temp = msg;
		if (!msg.empty() && msg[msg.length() - 1] == '\n')
			_temp = msg.substr(0, msg.length() - 2);

		if (!_temp.empty() && _temp[0] == ':')
		{
			_temp = _temp.substr(1);
			_cmd = getToNext();
		}
		_cmd = getToNext();

		while (!_temp.empty())
		{
			std::string param = getToNext();
			if (!param.empty())
				_params.push(param);
		}
		if (!_temp.empty())
			_params.push(_temp);
		setCommand(_cmd);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

Command::Command(const Command &other)
{
	*this = other;
}

Command::~Command()
{
}

std::string Command::getCommand() const
{
	return _cmd;
}

void Command::setCommand(const std::string &cmd)
{
	// TODO: Crear una función para que el comando esté en minúsculas
	_cmd = cmd;
}

Command &Command::operator=(const Command &other)
{
	_cmd = other._cmd;
	_params = other._params;
	_from = other._from;
	_targets = other._targets;
	_temp = other._temp;
	return *this;
}

const std::string &Command::getNextParam()
{
	std::string &param = _params.front();
	_params.pop();
	return param;
}

int Command::paramsSize()
{
	return _params.size();
}

std::queue<std::string> &Command::getTargets()
{
	return _targets;
}

const std::string &Command::getNextTarget()
{
	std::string &target = _targets.front();
	_targets.pop();
	return target;
}

int Command::targetsSize()
{
	return _targets.size();
}

int Command::getSender() const
{
	return _from;
}

int Command::generateTargets()
{
	if (!_params.empty())
	{
		std::string targets = getNextParam();
		//_targets.push(targets);
		std::list<std::string> rSplit = split(targets, ",");
		for (std::list<std::string>::iterator it = rSplit.begin(); it != rSplit.end(); it++)
		{
			_targets.push(*it);
		}
	}
	return 0;
}

std::list<std::string> Command::split(const std::string &str, std::string delimiter)
{
	size_t pos = 0;
	std::list<std::string> tokens;
	std::string targets(str);
	while ((pos = targets.find(delimiter)) != std::string::npos)
	{
		std::string token = targets.substr(0, pos);
		tokens.push_back(token);
		targets.erase(0, pos + delimiter.length());
	}
	if (!targets.empty())
		tokens.push_back(targets);
	return tokens;
}

std::string Command::toLowerString(std::string inputString)
{
	for (unsigned long i = 0; i < inputString.length(); i++)
		inputString[i] = tolower(inputString[i]);
	return inputString;
}

std::string Command::getMsg()
{
	return _msg;
}
