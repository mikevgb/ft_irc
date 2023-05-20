/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:43:45 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/05/20 10:38:10 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>
#include <list>
#include <map>
#include "include/Logger.hpp"
#include "User.hpp"

class User;

class Command
{
private:
	std::string _cmd;

	void initCommandMap();

public:
	Command(const std::string &cmd);
	Command(const Command &other);
	Command &operator=(const Command &other);
	~Command();
	std::string getCommand() const;
	void setCommand(const std::string &cmd);

	static const size_t MAX_PARAMS = 15;
	typedef int (*CommandFunction)(std::list<std::string>, User *); // Define the function pointer type
	std::map<std::string, CommandFunction> commandMap;

	// Command functions
	static int nick(std::list<std::string> params, User *);
	static int user(std::list<std::string> params, User *);
};

#endif
