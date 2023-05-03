
#include "Command.hpp"

const std::string Command::getToNext(const std::string &split)
{
    std::string result = std::string("");
    std::cout << "temp antes: " << _temp << std::endl;
    size_t pos;
    size_t pos1 = _temp.find_first_of(split, 0);
    size_t pos2 = _temp.find_first_of(":", 0);
    pos2 = pos2 == 0 ? std::string::npos : pos2;
    if (pos1 != std::string::npos && pos2 != std::string::npos)
        pos = pos1 < pos2 ? pos1 : pos2;
    else if (pos1 != std::string::npos)
        pos = pos1;
    else
        pos = pos2;
    if (pos != std::string::npos)
    {
        result = _temp.substr(0, pos);
        _temp = _temp.find(split);
        std::cout << "temp despues: " << _temp << std::endl;
        std::cout << "Resultado: " << result << std::endl;
    }
    return result;
}

Command::Command(int from, const std::string &msg)
    : _from(from), _msg(msg), _cmd(), _params()
{
    bool end = false;
    _temp = msg;
    _cmd = getToNext(" ");
    if (_cmd[0] == ':')
        _cmd = getToNext(" ");
    while (!end)
    {
        std::string param = getToNext(" ");
        if (!_temp.empty())
            _params.push(param);
        if (param.empty() || (!_temp.empty() && _temp[0] == ':'))
            end = true;
    }
    if (!_temp.empty())
        _params.push(_temp);
}

Command::~Command()
{
}

std::string Command::getCommand() const
{
    return _cmd;
}

void Command::setCommand(const std::string &cmd)
{
    _cmd = cmd;
}

Command &Command::operator=(const Command &other)
{
    _cmd = other._cmd;
    _params = other._params;
    _from = other._from;
    return *this;
}

const std::string &Command::getNextParam()
{
    std::string &param = _params.front();
    _params.pop();
    return param;
}

int Command::paramsSize()
{
    return _params.size();
}

std::queue<std::string> &Command::getTargets()
{
    return _targets;
}

const std::string &Command::getNextTarget()
{
    std::string &target = _targets.front();
    _targets.pop();
    return target;
}

int Command::targetsSize()
{
    return _targets.size();
}