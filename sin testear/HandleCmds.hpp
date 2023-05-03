#ifndef HANDLE_CMDS_H
#define HANDLE_CMDS_H
#include "lib.h"
#define PRIVMSG "PRIVMSG"
#define JOIN "JOIN"
#define USER "USER"

class User;

class CommandHandler
{
private:
    ListUsers _users;
    ListChannels _channels;
    // No es necesaria una lista de comandos porque se ejecutan según se pasan
    std::queue<ResultCmd> _listToSend;
    std::string _sender;
    Command *_cmd;
    void sendPRIVMSG(const std::string &nick);

public:
    CommandHandler();
    ~CommandHandler();
    std::list<ResultCmd> executeCmd(Command &cmd);
    User *newUser(const int fd);
    bool removeUser(const int fd);
};

#endif