#  🕊️ ft_irc

## 🛂 Table of Contents

1. [Introduction](#introduction)
2. [Project Description](#project-description)
3. [Features](#features)
4. [Installation](#installation)
5. [Usage](#usage)
6. [Contributing](#contributing)

### 🦮 Introduction

Internet Relay Chat or IRC is a textual communication protocol on the Internet [RFC 2812](https://www.rfc-editor.org/rfc/rfc2812).
It is instantaneous communication mainly in the form of discussions in groups via discussion channels, but can also be used for one-to-one communication.

### 📑 Project Description

The **ft_irc** project focuses on building a custom IRC server in C++. The IRC protocol enables real-time text communication between multiple users in channels or private messages. The project emphasizes network programming, socket communication, and concurrent handling of multiple connections.

### 🔖 Features

The **ft_irc** project includes the following features:

- Multiple simultaneous client connections.
- Support for multiple IRC commands, including JOIN, PART, PRIVMSG, NICK, etc.
- Channel creation and management (JOIN, PART, etc.).
- Private messaging between users.
- User authentication and registration.
- Error handling and graceful disconnection.

### :accessibility: Installation

To set up the **ft_irc** project on your local machine, follow these steps:

1. Clone the repository: `git clone https://github.com/MikelTolino/ft_irc.git`
2. Navigate to the project directory: `cd ft_irc`
3. Compile the server using the provided Makefile: `make`
5. Start the server: `./ircserv`

### 💁‍♂️ Usage

Once the server are running, you can use the client's command-line interface to interact with the IRC server. I strongly recommend using [Irssi](https://irssi.org/) but you can choose the IRC Client you want.

For more information on the available commands and their usage, refer to the documentation provided by your IRC Client.

### 🦸 Contributing

Contributions to the ft_irc project are welcome! If you find any bugs, have suggestions for improvements, or want to add new features, feel free to open an issue or submit a pull request. Please follow the established coding style and commit message conventions for a smooth integration process.

_Happy coding! 🚀_
