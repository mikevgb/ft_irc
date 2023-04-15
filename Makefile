NAME = pruebas

RM = rm -rf

CXX = g++

RM = rm -rf

CXXFLAGS =  -g -ggdb -Wall -Werror -Wextra -I include -D_GLIBCXX_DEBUG

SRCS =	User.cpp \
		Channel.cpp \
		ListUsers.cpp \
		ListChannels.cpp \
		Command.cpp \
		ResultCmd.cpp \
		HandleCmds.cpp \
		ServerMsgs.cpp \
		Msg.cpp \
		Socket.cpp \
		main.cpp
		#pruebas.cpp

OBJS =${SRCS:.cpp=.o}

${NAME} : ${OBJS}
	${CXX} ${CXXFLAGS} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all