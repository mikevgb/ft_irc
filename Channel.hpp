/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:43:53 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/06/26 17:05:24 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
#define CHANNEL_HPP
#include "lib2.h"

class Channel
{
private:
	std::string _name;
	std::string _topic;
	std::string _password;
	std::set<User *> _users;
	std::set<User *> _admins;
	std::set<User *> _invited;
	std::set<User *> _baned;
	size_t _limit;
	size_t _nbrUsers;
	bool _isPrivate;
	bool _isSecret;
	bool _isInviteOnly;
	bool _isModerate;
	bool _isTopicBlock;
	bool _isBlockOutside;

	static const size_t max_size = 50;

public:
	Channel(const std::string &name);
	~Channel();
	const std::string &getName() const;
	void setTopic(const std::string &topic);
	const std::string &getTopic() const;
	int addUser(User *user);
	int addAdmin(User *user);
	void inviteUser(User *user);
	void removeUser(User *user);
	bool setMode(std::string mode);
	int removeMode(char mode, User *admin, User *user);
	bool isEmpty() const;
	bool isUser(User *user) const;
	bool isAdmin(User *admin) const;
	bool isBaned(User *user) const;
	bool isInvited(User *user) const;
	bool isPrivate() const;
	bool isSecret() const;
	bool isInviteOnly() const;
	bool isModerate() const;
	bool isTopicBlock() const;
	bool isBlockOutside() const;
	int setPrivate(bool mode, User *user);
	int setSecret(bool mode, User *user);
	int setInviteOnly(bool mode, User *user);
	int setModerate(bool mode, User *user);
	int setTopicBlock(bool mode, User *user);
	int setBlockOutside(bool mode, User *user);
	bool setName(const std::string &name);
	std::set<User *> getUsers() const;
	std::string getModes() const;
	std::string getListUsers() const;
};

#endif
