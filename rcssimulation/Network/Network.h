//
// Created by Felipe Pereira <fnalmeidap> on 7/18/23.
// Copyright (c) 2023 RobôCIn. All rights reserved.
//
#ifndef RCSSIMULATION_NETWORK_H
#define RCSSIMULATION_NETWORK_H

#include "NetworkUtils.h"
#include "UDPSocket.h"

namespace Network {
    class Connection {
    public:
        static void connectToServer() {
           std::cout << Command::playerInit("MyTeam", 2.0);
        }

        static void disconnectFromServer() {
            std::cout << Command::playerBye();
        }
    };
}



#endif //RCSSIMULATION_NETWORK_H
