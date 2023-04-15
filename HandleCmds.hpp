#ifndef HANDLE_CMDS_H
#define HANDLE_CMDS_H
#include "lib2.h"
#define PRIVMSG "PRIVMSG"
#define JOIN "JOIN"
#define USER "USER"
#define CAPASUPPORTANSWER "CAP * LS :"

class User;
class ListUsers;
class ListChannels;
class Command;
class ResultCmd;

class HandleCmds
{
private:
    ListUsers *_users;
    ListChannels* _channels;
    // No es necesaria una lista de comandos porque se ejecutan según se pasan
    //std::queue<ResultCmd> *_listToSend;
    std::string _sender;
    Command *_cmd;
    int _firstTimeFlag;

    

public:
    void sendPRIVMSG( const std::string& nick);
    HandleCmds();
    ~HandleCmds();
    std::list<ResultCmd> executeCmd(Command* cmd);
    User* newUser(const int fd);
    bool removeUser(const int fd);
    ListUsers* getUsers();
    void sendFt(std::string sendToMySelf, int fd = 0); //if no fd is provided it will send to user that call's it
    std::list<ResultCmd> mierdaDeFuncionDeMiguelQueNoSabeProgramarNiEscuchar();
};

#endif