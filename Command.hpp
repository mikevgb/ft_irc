/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:43:45 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/05/15 15:15:26 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>
#include <queue>
#include <list>
#include <iostream>

class Command
{
private:
	int _from;
	std::string _msg;
	std::string _cmd;
	std::queue<std::string> _params;
	std::queue<std::string> _targets;
	std::string _temp;
	const std::string getToNext();

	static const size_t MAX_PARAMS = 15;

public:
	Command(int from, const std::string &msg);
	Command(const Command &other);
	~Command();
	std::string getCommand() const;
	void setCommand(const std::string &cmd);
	void addTarget(const std::string &user);
	std::list<std::string> &getNicks();
	int getSender() const;
	Command &operator=(const Command &other);
	void setParams(const std::string &params);
	std::string getParams();
	const std::string &getNextParam();
	int paramsSize();
	std::queue<std::string> &getTargets();
	const std::string &getNextTarget();
	int targetsSize();
	int generateTargets();
	static std::list<std::string> split(std::string msg, std::string delimiter);
	std::string toLowerString(std::string inputString);
	std::string getMsg();
};

#endif
