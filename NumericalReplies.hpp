/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NumericalReplies.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:29:27 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/06/11 16:40:22 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMERICAL_REPLIES_HPP
#define NUMERICAL_REPLIES_HPP

#include <string>

#define C_RPL_WELCOME "001"
#define C_RPL_YOURHOST "002"
#define C_RPL_CREATED "003"
#define C_RPL_MYINFO "004"
#define C_RPL_BOUNCE "005"
#define C_RPL_TRACELINK "200"
#define C_RPL_TRACECONNECTING "201"
#define C_RPL_TRACEHANDSHAKE "202"
#define C_RPL_TRACEUNKNOWN "203"
#define C_RPL_TRACEOPERATOR "204"
#define C_RPL_TRACEUSER "205"
#define C_RPL_TRACESERVER "206"
#define C_RPL_TRACENEWTYPE "208"
#define C_RPL_STATSLINKINFO "211"
#define C_RPL_STATSCOMMANDS "212"
#define C_RPL_STATSCLINE "213"
#define C_RPL_STATSNLINE "214"
#define C_RPL_STATSILINE "215"
#define C_RPL_STATSKLINE "216"
#define C_RPL_STATSYLINE "218"
#define C_RPL_ENDOFSTATS "219"
#define C_RPL_UMODEIS "221"
#define C_RPL_STATSLLINE "241"
#define C_RPL_STATSUPTIME "242" 
#define C_RPL_STATSOLINE "243"
#define C_RPL_STATSHLINE "244"
#define C_RPL_LUSERCLIENT "251"
#define C_RPL_LUSEROP "252"
#define C_RPL_LUSERUNKNOWN "253"
#define C_RPL_LUSERCHANNELS "254"
#define C_RPL_LUSERME "255"
#define C_RPL_ADMINME "256"
#define C_RPL_ADMINLOC1 "257"
#define C_RPL_ADMINLOC2 "258"
#define C_RPL_ADMINEMAIL "259"
#define C_RPL_TRACELOG "261"
#define C_RPL_TRACEEND "262"
#define C_RPL_TRYAGAIN "263"
#define C_RPL_NONE "300" 
#define C_RPL_AWAY "301"
#define C_RPL_USERHOST "302"
#define C_RPL_ISON "303"
#define C_RPL_UNAWAY "305" 
#define C_RPL_NOWAWAY "306" 
#define C_RPL_WHOISUSER "311"
#define C_RPL_WHOISSERVER "312"
#define C_RPL_WHOISOPERATOR "313"
#define C_RPL_WHOWASUSER "314"
#define C_RPL_ENDOFWHO "315"
#define C_RPL_WHOISIDLE "317"
#define C_RPL_ENDOFWHOIS "318"
#define C_RPL_WHOISCHANNELS "319"
#define C_RPL_LISTSTART "321" 
#define C_RPL_LIST "322"
#define C_RPL_LISTEND "323" 
#define C_RPL_CHANNELMODEIS "324"
#define C_RPL_UNIQOPIS "325"
#define C_RPL_NOTOPIC "331"
#define C_RPL_TOPIC "332"
#define C_RPL_INVITING "341"
#define C_RPL_SUMMONING "342"
#define C_RPL_INVITELIST "346"
#define C_RPL_ENDOFINVITELIST "347"
#define C_RPL_EXCEPTLIST "348"
#define C_RPL_VERSION "351"
#define C_RPL_WHOREPLY "352"
#define C_RPL_NAMREPLY "353"
#define C_RPL_LINKS "364"
#define C_RPL_ENDOFLINKS "365"
#define C_RPL_ENDOFNAMES "366"
#define C_RPL_BANLIST "367"
#define C_RPL_ENDOFBANLIST "368"
#define C_RPL_ENDOFWHOWAS "369"
#define C_RPL_INFO "371"
#define C_RPL_MOTD "372"
#define C_RPL_ENDOFINFO "374" 
#define C_RPL_MOTDSTART "375"
#define C_RPL_ENDOFMOTD "376" 
#define C_RPL_YOUREOPER "381" 
#define C_RPL_REHASHING "382"
#define C_RPL_YOURESERVICE "383"
#define C_RPL_TIME "391"
#define C_RPL_USERSSTART "392" 
#define C_RPL_USERS "393" 
#define C_RPL_ENDOFUSERS "394" 
#define C_RPL_NOUSERS "395" 
#define C_ERR_NOSUCHNICK "401"
#define C_ERR_NOSUCHSERVER "402"
#define C_ERR_NOSUCHCHANNEL "403"
#define C_ERR_CANNOTSENDTOCHAN "404"
#define C_ERR_TOOMANYCHANNELS "405"
#define C_ERR_WASNOSUCHNICK "406"
#define C_ERR_TOOMANYTARGETS "407" 
#define C_ERR_NOSUCHSERVICE "408"
#define C_ERR_NOORIGIN "409" 
#define C_ERR_NORECIPIENT "411"
#define C_ERR_NOTEXTTOSEND "412" 
#define C_ERR_NOTOPLEVEL "413"
#define C_ERR_WILDTOPLEVEL "414"
#define C_ERR_BADMASK "415"
#define C_ERR_UNKNOWNCOMMAND "421"
#define C_ERR_NOMOTD "422" 
#define C_ERR_NOADMININFO "423"
#define C_ERR_FILEERROR "424"
#define C_ERR_NONICKNAMEGIVEN "431" 
#define C_ERR_ERRONEUSNICKNAME "432"
#define C_ERR_NICKNAMEINUSE "433"
#define C_ERR_NICKCOLLISION "436"
#define C_ERR_USERNOTINCHANNEL "441"
#define C_ERR_NOTONCHANNEL "442"
#define C_ERR_USERONCHANNEL "443"
#define C_ERR_NOLOGIN "444"
#define C_ERR_SUMMONDISABLED "445" 
#define C_ERR_USERSDISABLED "446" 
#define C_ERR_NOTREGISTERED "451" 
#define C_ERR_NEEDMOREPARAMS "461"
#define C_ERR_ALREADYREGISTRED "462" 
#define C_ERR_NOPERMFORHOST "463" 
#define C_ERR_PASSWDMISMATCH "464" 
#define C_ERR_YOUREBANNEDCREEP "465" 
#define C_ERR_KEYSET "467"
#define C_ERR_CHANNELISFULL "471"
#define C_ERR_UNKNOWNMODE "472"
#define C_ERR_INVITEONLYCHAN "473"
#define C_ERR_BANNEDFROMCHAN "474"
#define C_ERR_BADCHANNELKEY "475"
#define C_ERR_BADCHANMASK "476"
#define C_ERR_NOCHANMODES "477"
#define C_ERR_BANLISTFULL "478"
#define C_ERR_NOPRIVILEGES "481" 
#define C_ERR_CHANOPRIVSNEEDED "482"
#define C_ERR_CANTKILLSERVER "483" 
#define C_ERR_RESTRICTED "484" 
#define C_ERR_UNIQOPPRIVSNEEDED "485" 
#define C_ERR_NOOPERHOST "491" 
#define C_ERR_UMODEUNKNOWNFLAG "501" 
#define C_ERR_USERSDONTMATCH "502" 

std::string RPL_WELCOME(std::string nick, std::string user, std::string host);
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
std::string ERR_TOOMANYTARGETS();
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
