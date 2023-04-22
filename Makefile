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
		HandleCmds.cpp \
		ServerMsgs.cpp \
		Msg.cpp \
		IRCServer.cpp \
		main.cpp
		#pruebas.cpp

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
