/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib2.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:43:04 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/05/14 18:51:56 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <list>
#include "ServerMsgs.hpp"
#include "User.hpp"
#include "Channel.hpp"
#include "ListUsers.hpp"
#include "ListChannels.hpp"
#include "ResultCmd.hpp"
#include "Command.hpp"
#include "CommandHandler.hpp"
#include "IRCServer.hpp"
#include "Message.hpp"
// #include <string>
#include <optional>

// socket libs
#include <netinet/ip.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/poll.h>
#include <unistd.h>
#include <iostream>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <netdb.h>
#include <chrono>
#include <ctime>
#include <cstring> //needed for linux
#include <fcntl.h>
