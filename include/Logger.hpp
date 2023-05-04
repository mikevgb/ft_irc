/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:44:17 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/05/04 12:21:41 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#define LOG_SILENT 0
#define LOG_ERR 1
#define LOG_ERROR 1
#define LOG_WARN 2
#define LOG_WARNING 2
#define LOG_INFO 3
#define LOG_DEBUG 5
#define LOG_DEFAULT 4

#define LOG_INIT_COUT() Logger log(std::cout, __PRETTY_FUNCTION__)
#define LOG_INIT_CERR() Logger log(std::cerr, __PRETTY_FUNCTION__)
#define LOG_INIT_CLOG() Logger log(std::clog, __PRETTY_FUNCTION__)
#define LOG_INIT_CUSTOM(X) Logger log((X), __PRETTY_FUNCTION__)

#define DEBUG "[ DEBUG   ]"
#define ERROR "\033[0;31m[ ERROR   ]\033[0;0m"
#define WARNING "\033[0;33m[ WARNING ]\033[0;0m"
#define INFO "\033[0;34m[ INFO    ]\033[0;0m"

class Logger
{
public:
	inline Logger(std::ostream &, unsigned, std::string);
	inline Logger(std::ostream &, std::string n);
	template <typename T>
	friend Logger &operator<<(Logger &l, const T &s);
	inline Logger &operator()(unsigned ll);
	inline void flush() { _fac.flush(); }
	friend std::string prep_level(Logger &l);
	friend std::string prep_name(Logger &l);
	static unsigned &_loglevel()
	{
		static unsigned _ll_internal = LOG_DEFAULT;
		return _ll_internal;
	};
	static Logger &getInstance()
	{
		static Logger instance(std::cout, __PRETTY_FUNCTION__); // Guaranteed to be destroyed && Instantiated on first use.
		return instance;
	}
	inline void set_log_level(unsigned ll) { _loglevel() = ll; }

private:
	unsigned _message_level;
	std::ostream &_fac;
	std::string _name;
};

inline std::string prep_level(Logger &l);
inline std::string prep_name(Logger &l);

// unsigned Logger::_loglevel = LOG_DEFAULT;

template <typename T>
Logger &operator<<(Logger &l, const T &s)
{
	if (l._message_level <= l._loglevel())
	{
		l._fac << s;
		return l;
	}
	else
	{
		return l;
	}
}

Logger::Logger(std::ostream &f, std::string n)
	: _message_level(LOG_SILENT), _fac(f), _name(n)
{
}

Logger::Logger(std::ostream &f, unsigned ll, std::string n)
	: _message_level(LOG_SILENT), _fac(f), _name(n)
{
	_loglevel() = ll;
}

// Original operator
/*
Logger &Logger::operator()(unsigned ll)
{
	_message_level = ll;
	if (_message_level <= _loglevel())
	{
		_fac << prep_level(*this) << prep_time(*this) << prep_name(*this) << ": ";
	}
	return *this;
}
*/

Logger &Logger::operator()(unsigned ll)
{
	_message_level = ll;
	if (_message_level <= _loglevel())
	{
		_fac << prep_level(*this) << ": ";
	}
	return *this;
}

std::string prep_level(Logger &l)
{
	switch (l._message_level)
	{
	case LOG_ERR:
		return ERROR;
		break;
	case LOG_WARN:
		return WARNING;
		break;
	case LOG_INFO:
		return INFO;
		break;
	case LOG_DEBUG:
		return DEBUG;
		break;
	default:
		return "";
	}
	return "";
}

static Logger logg(std::cout, "");

#endif
