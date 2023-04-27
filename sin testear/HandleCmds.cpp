
#include "CommandHandler.hpp"

CommandHandler::CommandHandler()
:_users(), _channels(),_listToSend(),_sender(),_cmd()
{ }

CommandHandler::~CommandHandler()
{ }


User* CommandHandler::newUser(const int fd)
{
    return _users.createUser(fd);
}

bool CommandHandler::removeUser(const int fd)
{
    return _users.removeUser(fd);
}

void CommandHandler::sendPRIVMSG( const std::string& nick)
{
    ResultCmd result;
    result.addUser(_users.getUser(nick)->getFd());
    std::string msg = _sender + PRIVMSG + _cmd->getParams();
    
    // que en sender se cargue el getFullName nick@user@server que debe devolver el usuario


}

std::list<ResultCmd> CommandHandler::executeCmd(Command& cmd)
{
    _cmd = &cmd;
    std::list<ResultCmd> results;
    User* sender = _users.getUser(_cmd->getSender());
    if (!_cmd->getCommand().compare("NICK"))
    {
        if (_cmd->paramsSize() == 0)
        {
            ResultCmd result(ERR_NEEDMOREPARAMS);
            result.addUser(_cmd->getSender());
            results.push_back(result);
            return results;
        }
        else
        {
            ResultCmd result(_users.setNick(cmd.getNextParam(), cmd.getSender()));
            result.addUser(cmd.getSender());
            results.push_back(result);
            return results;
        }
    }
    if (!_cmd->getCommand().compare("USER"))
    {
        if (_cmd->paramsSize() == 0)
        {
            ResultCmd result;
            result.setError(ERR_NEEDMOREPARAMS);
            result.addUser(_cmd->getSender());
            results.push_back(result);
            return results;
        }
        else
        {
            ResultCmd result(_users.setUser(cmd.getNextParam(), cmd.getSender()));
            result.addUser(cmd.getSender());
            results.push_back(result);
            return results;
        }
    }
    if (!_cmd->getCommand().compare("PRIVMSG"))
    {
        std::list<ResultCmd> results;
        std::queue<std::string> nicks = _cmd->getTargets();
        while(!nicks.empty())
        {
            ResultCmd result;
            User* user = _users.getUser(nicks.front());
            result.addUser(user->getFd());
            result.addToMsg(sender->getFullName() + " PRIVMSG " + user->getNick() + " " + cmd.getNextParam());
            results.push_back(result);
            nicks.pop();
            return results;
        }
    }
    if (!_cmd->getCommand().compare(PRIVMSG))
    {
    }
    if (!_cmd->getCommand().compare(PRIVMSG))
    {
        
    }
    if (!_cmd->getCommand().compare(PRIVMSG))
    {
        
    }

    delete _cmd;
    return results;

}
