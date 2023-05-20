/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandHandler.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:43:37 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/05/20 10:41:20 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HANDLER_HPP
#define COMMAND_HANDLER_HPP
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <list>
#include "ServerMsgs.hpp"
#include "User.hpp"
#include "Channel.hpp"
#include "ListUsers.hpp"
#include "ListChannels.hpp"
#include "ResultCmd.hpp"
#include "Command.hpp"
#include "Message.hpp"
#include "Reply.hpp"

class User;
class ListUsers;
class ListChannels;
class Command;
class ResultCmd;
class Message;
class Reply;

class CommandHandler
{
private:
	ListUsers *_listUsers;
	ListChannels *_listChannels;
	User *_sender;
	std::list<std::string> _targets;
	std::list<User *> _targets2;
	Command *_cmd;
	Message _msg;
	int _firstTimeFlag;

public:
	CommandHandler(ListUsers *listUsers, ListChannels *listChannels);
	~CommandHandler();
	int executeCmd();
	ListUsers *getUsers();
	Message getMessage() const;
	void setMessage(const Message msg);
	void setUser(const int fd);
	std::list<User *> getTargets() const;

};

#endif
