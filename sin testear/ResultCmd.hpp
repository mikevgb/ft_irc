#ifndef RESULT_CMD
#define RESULT_CMD
#include <string>
#include <set>

class ResultCmd
{
private:
    bool _hasError;
    int _resultCode;
    std::string _msg;
    std::set<int> _users;
public:
    ResultCmd();
    ResultCmd(int resultCode);
    ~ResultCmd();
    void setMsg(const std::string& msg);
    void addToMsg(const std::string& msg);
    void addUser(int fd);
    void setUsers(const std::set<int>& fds);
    void setError(int errorCode);
    const std::string& getMsg();
    std::set<int>& getUsers();
};

ResultCmd::ResultCmd()
:_msg(), _users()
{
    _hasError = false;
}

ResultCmd::ResultCmd(int resultCode)
:_resultCode(resultCode),_msg(), _users()
{
    _hasError = false;
}

ResultCmd::~ResultCmd()
{
}

void ResultCmd::setMsg(const std::string& msg)
{
    _msg = msg;
}

void ResultCmd::addToMsg(const std::string& msg)
{
    _msg += msg;
}

void ResultCmd::addUser(int fd)
{
    _users.insert(fd);
}

void ResultCmd::setUsers(const std::set<int>& fds)
{
    _users = fds;
}

const std::string& ResultCmd::getMsg()
{
    if (_msg.empty())
    {
        //TODO desde aquí se monta el mensaje, si no existe ya
    }
    
    return _msg;
}

std::set<int>& ResultCmd::getUsers()
{
    return _users;
}

#endif