//
// Created by Felipe Pereira <fnalmeidap> on 7/18/23.
// Copyright (c) 2023 RobôCIn. All rights reserved.
//
#ifndef RCSSIMULATION_NETWORKUTILS_H
#define RCSSIMULATION_NETWORKUTILS_H

#include <bits/stdc++.h>

class PlayerCommand {
public:
    enum CommandType {
        INIT,
        RECONNECT,
        BYE,
        MOVE,
        DASH,
        TURN,
        KICK,
        CATCH,
        TACKLE,
        TURN_NECK,
        CHANGE_VIEW,
        CHANGE_FOCUS,
        SAY,
        POINTTO,
        ATTENTIONTO,
        CLANG,
        EAR,
        SENSE_BODY,
        SCORE,
        COMPRESSION,
        DONE,
        ILLEGAL
    };

    virtual std::string toString() const = 0;
};

class PlayerInitCommand : PlayerCommand{

};

#endif //RCSSIMULATION_NETWORKUTILS_H
