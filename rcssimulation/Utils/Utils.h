//
// Created by Mateus Ferreira <mateusfbsoares> on 12/19/23.
// Copyright (c) 2023 RobôCIn. All rights reserved.
//
#include <sys/select.h>

#define MESSAGE_BUFFER_SIZE 8192
#define DEFAULT_SERVER_UDP_PORT 6000

int is_fd_set(int fd){
    fd_set fdset;
    struct timeval timeout;

    FD_ZERO(&fdset);
    FD_SET( fd, &fdset);
    timeout.tv_sec = 0;
    timeout.tv_usec = 0;

    return select( fd+1, &fdset, nullptr, nullptr, &timeout);

}