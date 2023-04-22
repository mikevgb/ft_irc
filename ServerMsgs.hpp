#ifndef SERVER_MSG_H
#define SERVER_MSG_H
#include "Msg.hpp"
#define SERVER ":localhost "
#define LINE_BREAK "\n"
#define DUPLICATE_NICK_MSG "Nickname is already in use"
#define WELCOME_MSG "Welcome to the Internet Relay Network"
#define ERR_NICKNAMEINUSE 433
#define ERR_CHANNELISFULL 471
#define ERR_BADCHANNELKEY 475
#define ERR_INVITEONLYCHAN 473
#define ERR_BANNEDFROMCHAN 474
#define ERR_CHANOPRIVSNEEDED 482
#define ERR_NEEDMOREPARAMS 461
#define DUPLICATE_NICK_MSG "Nickname is already in use"
#define CODE_WELCOME 1
#define WELCOME ": Welcome to the Internet Relay Network"
#define RPL_NAMREPLY "353"
#define RPL_ENDOFNAMES "366"
#define RPL_TOPIC "332"
#define END_NAME_LIST " :End of /NAMES list."

class ServerMsgs
{
private:
public:
    ServerMsgs(/* args */);
    ~ServerMsgs();
    static std::string getColon();
    static std::string getWelcomeMsg(const std::string &nick, const std::string &user);
    static std::string getErrNickname(const std::string &nick);
    /*
    static std::string getResponseTopicChannel(const std::string& channel,const std::string& nick, const std::string& topic);
    static std::string getResponseUsersChannel(const std::string& channel,const std::string& nick, const std::string& users);
    static std::string getResponseEndUsersChannel(const std::string& channel,const std::string& nick, const std::string& topic);
    */
};

#endif
