# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 12:42:39 by mmateo-t          #+#    #+#              #
#    Updated: 2023/05/14 13:54:17 by mmateo-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= ircserv
CXX:= g++
RM:= rm -rf
#CXXFLAGS:= -Wall -Werror -Wextra
CPPSTD:= -std=c++98 -pedantic
CXXFLAGS:=  -g -ggdb -Wall -Werror -Wextra -I include -D_GLIBCXX_DEBUG $(CPPSTD)
SRCS:=	User.cpp \
		Channel.cpp \
		ListUsers.cpp \
		ListChannels.cpp \
		Command.cpp \
		ResultCmd.cpp \
		CommandHandler.cpp \
		ServerMsgs.cpp \
		Msg.cpp \
		IRCServer.cpp \
		Socket.cpp \
		Message.cpp \
		main.cpp

OBJS:= $(SRCS:%.cpp=%.o)

all: ${NAME}

${NAME} : ${OBJS}
	${CXX} ${CXXFLAGS} -o ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all fclean clean re
