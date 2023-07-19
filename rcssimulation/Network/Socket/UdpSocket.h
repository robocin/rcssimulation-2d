//
// Created by Jeferson Araujo <jefersonseverino> on 7/18/23.
// Copyright (c) 2023 RobôCIn. All rights reserved.
//
#ifndef RCSSIMULATION_UDPSOCKET_H
#define RCSSIMULATION_UDPSOCKET_H

#include <sys/socket.h>

class UdpSocket {
public:
    /*!
     \brief rcssserver host name
    */
    std::string serverHostname;

    /*!
      \brief rcssserver port number
    */
    int serverPort;
    int socketType;
    int fileDescriptor;

    enum SocketType {
        DATAGRAM_TYPE,
        STREAM_TYPE,
        UNKNOWN_TYPE,
    };

    UdpSocket() : serverHostname("localhost"), serverPort(6000)
    {}

    bool open(const SocketType type) {
        switch (type) {
            case STREAM_TYPE:
                socketType = SOCK_STREAM;
                break;
            case DATAGRAM_TYPE:
                socketType = SOCK_DGRAM;
                break;
            default:
                std::cerr << "Unknow socket type" << std::endl;
                return false;
        }

        fileDescriptor = ::socket(AF_INET, socketType, 0);

    }

};


#endif //RCSSIMULATION_UDPSOCKET_H
