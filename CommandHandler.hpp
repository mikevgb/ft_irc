/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandHandler.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:43:37 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/06/02 18:46:20 by mmateo-t         ###   ########.fr       */
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
#include "Message.hpp"
#include "Reply.hpp"

class User;
class ListUsers;
class ListChannels;
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
	Message _msg;
	int _firstTimeFlag;

	typedef void (CommandHandler::*CommandFunction)(std::list<std::string>, User *, std::list<Reply> &); // Define the function pointer type
	std::map<std::string, CommandFunction> commandMap;

	void initCommandMap();

public:
	CommandHandler(ListUsers *listUsers, ListChannels *listChannels);
	~CommandHandler();
	void executeCmd(std::list<Reply> &);
	ListUsers *getUsers();
	Message getMessage() const;
	void setMessage(const Message msg);
	void setUser(const int fd);
	std::list<User *> getTargets() const;


	// Command functions
	void nick(std::list<std::string> params, User *, std::list<Reply> &);
	void user(std::list<std::string> params, User *, std::list<Reply> &);
	void quit(std::list<std::string> params, User *, std::list<Reply> &);

};

#endif
