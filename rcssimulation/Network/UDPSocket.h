//
// Created by Jeferson Araujo <jefersonseverino> on 7/18/23.
// Copyright (c) 2023 RobôCIn. All rights reserved.
//
#ifndef RCSSIMULATION_UDPSOCKET_H
#define RCSSIMULATION_UDPSOCKET_H

#include <stdlib.h>
#include <string>

#include <sys/socket.h>
#include <cstring>
#include <netinet/in.h>
#include <arpa/inet.h>


class UDPSocket {
private:
    const u_int16_t BUFFER_SIZE = 8192; //?why u_int16_t instead of char?
    int socket_fd;
    const char *serverHostname;
    u_int16_t serverPort;
    struct sockaddr_in serverAddress;
    struct sockaddr_in clientAddress;

public:
    inline UDPSocket() : serverHostname("localhost"), serverPort(6000) {

        // creates a socket
        socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
        if(socket_fd == -1){perror("failed to create socket"); exit(EXIT_FAILURE);}
        // define server adress and port
        std::memset(&serverAddress, 0, sizeof(serverAddress));
        serverAddress.sin_family = AF_INET;
        serverAddress.sin_port = htons(serverPort);
        inet_pton(AF_INET, serverHostname, &serverAddress.sin_addr);
    };

    inline int sendMessage(const char* message) {
        int messageLength = std::strlen(message);
        return sendto(socket_fd,
                               message,
                               messageLength,
                               0,
                               (struct sockaddr*)&serverAddress,
                               sizeof(serverAddress));
    }

    inline std::string receiveMessage() {
        char buffer[BUFFER_SIZE];
        socklen_t clientAddressLength = sizeof(clientAddress);
        int bytesReceived = recvfrom(socket_fd,
                                     buffer,
                                     BUFFER_SIZE - 1,
                                     0,
                                     (struct sockaddr*) &clientAddress,
                                     &clientAddressLength);
        return bytesReceived == -1 ? "" : [&]() -> std::string {
            return buffer;
        }();
    }

    inline int get_socket_fd()
    {
        return socket_fd;
    }
};


#endif //RCSSIMULATION_UDPSOCKET_H
