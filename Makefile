# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 12:42:39 by mmateo-t          #+#    #+#              #
#    Updated: 2023/06/05 16:22:37 by mmateo-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PORT= 4242
PASSWORD=""
NAME:= ircserv
CXX:= g++
RM:= rm -rf
CPPSTD:= -std=c++98 -pedantic
CXXFLAGS:=  -g -Wall -Werror -Wextra $(CPPSTD)
SRCS:=	User.cpp \
		Channel.cpp \
		ListUsers.cpp \
		ListChannels.cpp \
		CommandHandler.cpp \
		Msg.cpp \
		IRCServer.cpp \
		Socket.cpp \
		Message.cpp \
		Reply.cpp \
		NumericalReplies.cpp \
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

run: all
	./ircserv $(PORT) $(PASSWORD)

.PHONY: all fclean clean re
