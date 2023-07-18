//
// Created by Felipe Pereira <fnalmeidap> on 7/18/23.
// Copyright (c) 2023 RobôCIn. All rights reserved.
//

#ifndef RCSSIMULATION_ENTITIES_H
#define RCSSIMULATION_ENTITIES_H

#include <bits/stdc++.h>

class RobocinPlayer {
    RobocinPlayer()= default;
    ~RobocinPlayer()= default;

public:
    static inline void say(){
        std::cout << "Hi from entity" << std::endl;
    }
};

#endif //RCSSIMULATION_ENTITIES_H
