//
// Created by Felipe Pereira <fnalmeidap> on 7/18/23.
// Copyright (c) 2023 RobôCIn. All rights reserved.
//

#include "rcssimulation/Network/Network.h"

int main(){
    Network::Connection::connectToServer();
    Network::Connection::disconnectFromServer();
    return 1;
}