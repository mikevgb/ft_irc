
#include "User.hpp"

User::User(size_t fd)
:_fd(fd),_nick(), _user(),_channels()
{
    _isLogged = false;
}

User::~User()
{

}

size_t User::getFd()
{
    return _fd;
}

void User::setNick(const std::string& nick)
{
    _nick = nick;
}
const std::string& User::getNick() const
{
    return _nick;
}

void User::setUser(const std::string& user)
{
    _user = user;
}
const std::string& User::getUser() const
{
    return _user;
}

bool User::isLogged() const
{
    return _isLogged;
}
int User::changeToLogged()
{
    _isLogged = true;
    return 0;
}

const std::string User::getFullName() const
{
    return std::string(Msg::getColon() + _nick + Msg::getExclamation() + _user + Msg::getAt() + Msg::getServerName());
}

void User::addChannel(Channel* channel)
{
    _channels.insert(channel);
}

void User::removeChannel(Channel* channel)
{
    _channels.erase(channel);
}

bool User::operator==(const User& other) const
{
    return (_fd == other._fd);
}

void User::eraseUser()
{
    std::set<Channel*>::iterator it;
    for (it = _channels.begin(); it != _channels.end(); it++)
    {
        //it->removeUser(*this);
    }
}
