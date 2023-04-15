#ifndef RESULT_CMD
#define RESULT_CMD
#include <string>
#include <set>
#include "lib2.h"

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
    int getResultCode();
    const std::string& getMsg();
    std::set<int>& getUsers();
};

#endif