//
// Created by Mateus Ferreira <mateusfbsoares> on 12/19/23.
// Copyright (c) 2023 RobôCIn. All rights reserved.
//

#include "rcssimulation/Utils/Utils.h"
#include "rcssimulation/Network/UDPSocket.h"
#include <iostream>

void send_command_from_stdin(UDPSocket udp_conn)
{
    char msg_buffer[MESSAGE_BUFFER_SIZE];
    std::cin.getline(msg_buffer, sizeof(char)*MESSAGE_BUFFER_SIZE);
    udp_conn.sendMessage(msg_buffer);
}

void get_and_print_server_msg(UDPSocket udp_conn)
{
    std::string msg = udp_conn.receiveMessage();
    std::cout << msg << std::endl;
}


void messageLoop()
{
    UDPSocket udp_conn = UDPSocket();
    while(true)
    {
        if(is_fd_set(fileno(stdin)))
        {
            send_command_from_stdin(udp_conn);
        }

        if(is_fd_set(udp_conn.get_socket_fd()))
        {
            get_and_print_server_msg(udp_conn);
        }
    }
}

int main()
{
    messageLoop();
}