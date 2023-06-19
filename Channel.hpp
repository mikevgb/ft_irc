/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:43:53 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/06/15 12:53:32 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
#define CHANNEL_HPP
#include "lib2.h"
/*****************************
  o - give/take channel operator privileges;*
  p - private channel flag;*
  s - secret channel flag;*
  i - invite-only channel flag;*
  t - topic settable by channel operator only flag;*
  n - no messages to channel from clients on the outside;*
  m - moderated channel;*
  When mode +m is set, any users with a powerlevel of 0 (i.e. not opped or voiced) will be prevented from talking.
  l - set the user limit to channel;*
  b - set a ban mask to keep users out;
  v - give/take the ability to speak on a moderated channel;
  k - set a channel key (password).

	ERR_NEEDMOREPARAMS              RPL_CHANNELMODEIS
	ERR_CHANOPRIVSNEEDED            ERR_NOSUCHNICK
	ERR_NOTONCHANNEL                ERR_KEYSET
	RPL_BANLIST                     RPL_ENDOFBANLIST
	ERR_UNKNOWNMODE                 ERR_NOSUCHCHANNEL

	ERR_USERSDONTMATCH              RPL_UMODEIS
	ERR_UMODEUNKNOWNFLAG
*****************************/

// class User;

class Channel
{
private:
	std::string _name;
	std::string _topic;
	std::string _password;
	std::set<User *> _users;
	std::set<User *> _admins;
	std::set<User *> _voiced;
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
	int setTopic(const std::string &topic, User *user);
	const std::string &getTopic() const;
	int addUser(User *user);
	int addAdmin(User *user);
	int inviteUser(User *user, User *admin);
	void removeUser(User *user);
	void setVoiceUser(User *user);
	void removeVoiceUser(User *user);
	void setBanUser(User *user);
	void removeBanUser(User *user);
	int setMode(char mode, User *admin, User *user, const std::string &param);
	int removeMode(char mode, User *admin, User *user);
	bool isEmpty() const;
	bool isUser(User *user) const;
	bool isAdmin(User *admin) const;
	bool isBaned(User *user) const;
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
