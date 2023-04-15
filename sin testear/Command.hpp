#ifndef COMMAND_H
#define COMMAND_H
#include "lib.h"

class Command
{
private:
	int _from;
	std::string _msg;
    std::string _cmd;
    std::queue<std::string> _params;
    std::queue<std::string> _targets;
    std::string _temp;
    const std::string getToNext(const std::string& split);
public:
    Command(int from, const std::string& msg);
    ~Command();
    std::string getCommand() const;
    void setCommand(const std::string& cmd);
    void addTarget(const std::string& user);
    std::list<std::string>& getNicks();
    int getSender() const;
    Command& operator=( const Command& other );
    void setParams( const std::string& params);
    std::string getParams();
	const std::string& getNextParam();
	int paramsSize();
    std::queue<std::string>& getTargets();
    const std::string& getNextTarget();
    int targetsSize();
};

#endif
