/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NumericalReplies.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:29:27 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/06/05 16:32:34 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMERICAL_REPLIES_HPP
#define NUMERICAL_REPLIES_HPP

#include <string>

std::string RPL_WELCOME(std::string prefix);
std::string RPL_YOURHOST(std::string servername, std::string ver);
std::string RPL_CREATED(std::string date);
std::string RPL_MYINFO(std::string servername, std::string version, std::string umodes, std::string cmodes);
std::string RPL_BOUNCE(std::string server, std::string port);
std::string RPL_TRACELINK(std::string version, std::string destination, std::string server);
std::string RPL_TRACECONNECTING(std::string class1, std::string server);
std::string RPL_TRACEHANDSHAKE(std::string class1, std::string server);
std::string RPL_TRACEUNKNOWN(std::string class1, std::string ip);
std::string RPL_TRACEOPERATOR(std::string class1, std::string nick);
std::string RPL_TRACEUSER(std::string class1, std::string nick);
std::string RPL_TRACESERVER(std::string class1, std::string int1, std::string int2, std::string server, std::string nick, std::string user, std::string host);
std::string RPL_TRACENEWTYPE(std::string type, std::string name);
std::string RPL_STATSLINKINFO(std::string name, std::string q, std::string smessages, std::string sbytes, std::string rsmessages, std::string rbytes, std::string time);
std::string RPL_STATSCOMMANDS(std::string command, std::string count);
std::string RPL_STATSCLINE(std::string host, std::string name, std::string port, std::string class1);
std::string RPL_STATSNLINE(std::string host, std::string name, std::string port, std::string class1);
std::string RPL_STATSILINE(std::string host1, std::string host2, std::string port, std::string class1);
std::string RPL_STATSKLINE(std::string host, std::string user, std::string port, std::string class1);
std::string RPL_STATSYLINE(std::string class1, std::string ping, std::string connect, std::string max);
std::string RPL_ENDOFSTATS(std::string letter);
std::string RPL_UMODEIS(std::string mode);
std::string RPL_STATSLLINE(std::string host, std::string name, std::string depth);
std::string RPL_STATSUPTIME();
std::string RPL_STATSOLINE(std::string mask, std::string name);
std::string RPL_STATSHLINE(std::string mask, std::string name);
std::string RPL_LUSERCLIENT(std::string int1, std::string int2, std::string int3);
std::string RPL_LUSEROP(std::string int1);
std::string RPL_LUSERUNKNOWN(std::string int1);
std::string RPL_LUSERCHANNELS(std::string int1);
std::string RPL_LUSERME(std::string int1, std::string int2);
std::string RPL_ADMINME(std::string server);
std::string RPL_ADMINLOC1(std::string info);
std::string RPL_ADMINLOC2(std::string info);
std::string RPL_ADMINEMAIL(std::string info);
std::string RPL_TRACELOG(std::string file, std::string level);
std::string RPL_TRACEEND(std::string server, std::string version);
std::string RPL_TRYAGAIN(std::string cmd);
std::string RPL_NONE();
std::string RPL_AWAY(std::string nick, std::string message);
std::string RPL_USERHOST(std::string reply_list);
std::string RPL_ISON(std::string nick_list);
std::string RPL_UNAWAY();
std::string RPL_NOWAWAY();
std::string RPL_WHOISUSER(std::string nick, std::string user, std::string host, std::string real);
std::string RPL_WHOISSERVER(std::string nick, std::string server, std::string info);
std::string RPL_WHOISOPERATOR(std::string nick);
std::string RPL_WHOWASUSER(std::string nick, std::string user, std::string host, std::string real);
std::string RPL_ENDOFWHO(std::string name);
std::string RPL_WHOISIDLE(std::string nick, std::string integer);
std::string RPL_ENDOFWHOIS(std::string nick);
std::string RPL_WHOISCHANNELS(std::string nick, std::string channel);
std::string RPL_LISTSTART();
std::string RPL_LIST(std::string channel, std::string nbrUser, std::string topic);
std::string RPL_LISTEND();
std::string RPL_CHANNELMODEIS(std::string channel, std::string mode, std::string params);
std::string RPL_UNIQOPIS(std::string channel, std::string nick);
std::string RPL_NOTOPIC(std::string channel);
std::string RPL_TOPIC(std::string channel, std::string topic);
std::string RPL_INVITING(std::string channel, std::string nick);
std::string RPL_SUMMONING(std::string user);
std::string RPL_INVITELIST(std::string channel, std::string inviter);
std::string RPL_ENDOFINVITELIST(std::string channel);
std::string RPL_EXCEPTLIST(std::string channel, std::string mask);
std::string RPL_ENDOFEXCEPTLIST(std::string channel);
std::string RPL_VERSION(std::string version, std::string server, std::string comments);
std::string RPL_WHOREPLY(std::string channel, std::string user, std::string host, std::string server, std::string nick, std::string state, std::string real);
std::string RPL_NAMREPLY(std::string chan_mod, std::string channel, std::string nick_list);
std::string RPL_LINKS(std::string mask, std::string server, std::string hopcount, std::string info);
std::string RPL_ENDOFLINKS(std::string mask);
std::string RPL_ENDOFNAMES(std::string channel);
std::string RPL_BANLIST(std::string channel, std::string banip);
std::string RPL_ENDOFBANLIST(std::string channel);
std::string RPL_ENDOFWHOWAS(std::string nick);
std::string RPL_INFO(std::string string);
std::string RPL_MOTD(std::string text);
std::string RPL_ENDOFINFO();
std::string RPL_MOTDSTART(std::string server);
std::string RPL_ENDOFMOTD();
std::string RPL_YOUREOPER();
std::string RPL_REHASHING(std::string file);
std::string RPL_YOURESERVICE(std::string nick);
std::string RPL_TIME(std::string server, std::string time);
std::string RPL_USERSSTART();
std::string RPL_USERS();
std::string RPL_ENDOFUSERS();
std::string RPL_NOUSERS();
std::string ERR_NOSUCHNICK(std::string nickname);
std::string ERR_NOSUCHSERVER(std::string server);
std::string ERR_NOSUCHCHANNEL(std::string channel);
std::string ERR_CANNOTSENDTOCHAN(std::string channel);
std::string ERR_TOOMANYCHANNELS(std::string channel);
std::string ERR_WASNOSUCHNICK(std::string nickname);
std::string ERR_TOOMANYTARGETS(std::string target);
std::string ERR_NOSUCHSERVICE(std::string service);
std::string ERR_NOORIGIN();
std::string ERR_NORECIPIENT(std::string command);
std::string ERR_NOTEXTTOSEND();
std::string ERR_NOTOPLEVEL(std::string mask);
std::string ERR_WILDTOPLEVEL(std::string mask);
std::string ERR_BADMASK(std::string mask);
std::string ERR_UNKNOWNCOMMAND(std::string command);
std::string ERR_NOMOTD();
std::string ERR_NOADMININFO(std::string server);
std::string ERR_FILEERROR(std::string op, std::string file);
std::string ERR_NONICKNAMEGIVEN();
std::string ERR_ERRONEUSNICKNAME(std::string nick);
std::string ERR_NICKNAMEINUSE(std::string nick);
std::string ERR_NICKCOLLISION(std::string nick);
std::string ERR_USERNOTINCHANNEL(std::string nick, std::string channel);
std::string ERR_NOTONCHANNEL(std::string channel);
std::string ERR_USERONCHANNEL(std::string user, std::string channel);
std::string ERR_NOLOGIN(std::string user);
std::string ERR_SUMMONDISABLED();
std::string ERR_USERSDISABLED();
std::string ERR_NOTREGISTERED();
std::string ERR_NEEDMOREPARAMS(std::string command);
std::string ERR_ALREADYREGISTRED();
std::string ERR_NOPERMFORHOST();
std::string ERR_PASSWDMISMATCH();
std::string ERR_YOUREBANNEDCREEP();
std::string ERR_KEYSET(std::string channel);
std::string ERR_CHANNELISFULL(std::string channel);
std::string ERR_UNKNOWNMODE(std::string c);
std::string ERR_INVITEONLYCHAN(std::string channel);
std::string ERR_BANNEDFROMCHAN(std::string channel);
std::string ERR_BADCHANNELKEY(std::string channel);
std::string ERR_BADCHANMASK(std::string channel);
std::string ERR_NOCHANMODES(std::string channel);
std::string ERR_BANLISTFULL(std::string channel);
std::string ERR_NOPRIVILEGES();
std::string ERR_CANTKILLSERVER();
std::string ERR_RESTRICTED();
std::string ERR_CHANOPRIVSNEEDED(std::string channel);
std::string ERR_UNIQOPPRIVSNEEDED();
std::string ERR_NOOPERHOST();
std::string ERR_UMODEUNKNOWNFLAG();
std::string ERR_USERSDONTMATCH();

std::string getReplies(unsigned short code, std::string arg1, std::string arg2, std::string arg3, std::string arg4, std::string arg5, std::string arg6, std::string arg7);

#endif
