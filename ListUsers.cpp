
#include "ListUsers.hpp"

ListUsers::ListUsers(/* args */)
:_usersByName(), _usersByFd()
{
}

ListUsers::~ListUsers()
{
}

bool ListUsers::addUser(User* user)
{
    if (_usersByName.find(user->getNick())==_usersByName.end())
    {
        std::cout << "nick " << user->getNick() << std::endl;
        _usersByName.insert(std::pair<std::string, User*>(user->getNick(), user));
        std::cout << "nick " << user->getNick() << std::endl;
        std::cout << "user " <<  _usersByName[user->getNick()]->getUser() << std::endl;
        return true;
    }
    return false;
}

User* ListUsers::createUser(const size_t fd)
{
    //TODO: No debería pasar, pero ver que hacer si ya exite el fd
    User* user = new User(fd);
    std::map<size_t, User *>::iterator it = _usersByFd.find(fd);
    std::map<size_t, User *>::iterator it2 = _usersByFd.end();
    std::cout << "New user created with fd " << fd << std::endl;
    if ( it!=it2)
    {
        std::cout << "MIGUEL!!!! ME CAGO EN TUS MUERTOS!!!!!" << std::endl;
        return NULL;
    }    
    _usersByFd[user->getFd()] = user;
    return user;
}


int ListUsers::setNick(const std::string& nick, const size_t fd)
{
    std::cout << "set nick: " << nick << std::endl;
    //TODO comprobar que pasa en IRC si el usuario que tiene size_tenta ponerse el mismo nick
    User* user = getUser(fd);
    const std::string& oldNick = user->getNick();
    if (_usersByName.find(nick)==_usersByName.end())
    {
        user->setNick(nick);
        if (user->isLogged())
        {
            _usersByName.erase(oldNick);
            addUser(user);
            return 0;
        }
        else if (!user->isLogged() && user->getUser().length() > 0)
        {
            user->changeToLogged();
            addUser(user);
            std::cout << "nick 2: " << user->getNick() << std::endl;
            return CODE_WELCOME;
        }
    } else if(oldNick != nick) {
        return ERR_NICKNAMEINUSE;
    }
    return 0;
}

int ListUsers::setUser(const std::string& name, const size_t fd)
{
    //TODO crear excepciones si no existe el usuario en la lista
    User* user = getUser(fd);
    user->setUser(name);
    std::cout << "nick: " << user->getNick() << std::endl;
    std::cout << "user: " << user->getUser() << std::endl;
    if (!user->isLogged() && user->getNick().length() > 0)
    {
        user->changeToLogged();
        addUser(user);
        std::cout << "user 2: " << user->getUser() << std::endl;
        return CODE_WELCOME;
    }
    return 0;
}

User* ListUsers::getUser(const std::string& nick)
{
    std::cout << "buscar por: " << nick << std::endl;
    if (_usersByName.find(nick) != _usersByName.end())
        return _usersByName[nick];
    return NULL;
}
User* ListUsers::getUser(const size_t fd)
{
    //TODO comprobar si existe
    return _usersByFd[fd];
}

int ListUsers::removeUser(const size_t fd)
{
    try
    {
        User* user = getUser(fd);
        user->eraseUser();
        _usersByName.erase(user->getNick());
        _usersByFd.erase(fd);
        delete user;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    return 0;
}

ListUsers::iterator ListUsers::begin()
{
    return _usersByName.begin();
}

ListUsers::iterator ListUsers::end()
{
    return _usersByName.end();
}