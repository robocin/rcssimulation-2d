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
    // get command (stdin input)
    std::cin.getline(msg_buffer, sizeof(char)*MESSAGE_BUFFER_SIZE);
    // send stdin input to socket
    udp_conn.sendMessage(msg_buffer);
}

void get_and_print_server_msg(UDPSocket udp_conn)
{
    // Check for socket input
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

/*
int _messageLoop()
{

    // declare the message buffer
    char msg_buffer[MESSAGE_BUFFER_SIZE];
    std::memset( &msg_buffer, 0, sizeof(char)*MESSAGE_BUFFER_SIZE);

    struct sockaddr_in servaddr = {0};
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd == -1)
    {
        perror("failed to create socket");
        exit(EXIT_FAILURE);
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(6000);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    // Check stdin for input
    if (std::cin.peek() != EOF)
    {
        // get stdin input
        std::cin.getline(msg_buffer, sizeof(char)*MESSAGE_BUFFER_SIZE);
        // send stdin input to socket
        int _len = sendto(sockfd, (const char *)msg_buffer, strlen(msg_buffer),
                            0, (const struct sockaddr *)&servaddr, sizeof(servaddr));
        if( _len == -1)
        {
            perror("failed to send");
            close(sockfd);
        }
    }

    std::cout << "######### STARTING #########" << std::endl;

    while (true){

        // Check server port 
        ssize_t bytesRead = recvfrom(sockfd, msg_buffer, sizeof(char)*MESSAGE_BUFFER_SIZE, 0, nullptr, nullptr);
        if (bytesRead > 0)
        {
            std::cout << "SERVER: " << std::string(msg_buffer, bytesRead) << std::endl;
        }
    }
}
*/
