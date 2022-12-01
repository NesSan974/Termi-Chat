//------------------------------------------------
// INCLUDES
//------------------------------------------------
#include <sys/socket.h>
#include <arpa/inet.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <threads.h>

#include "./include/struct.h"
#include "./include/List.h"

int main(int argc, char const *argv[])
{

    // variable pour la connection socket
    int socketServer;

    // all client connected
    List *allClient;
    printf("starting..\n");

    // variable pour les threads
    thrd_t onConCl;

    // variable pour la connection socket
    socketServer = socket(AF_INET, SOCK_STREAM, 0);

    // verification du socket
    if (socketServer == -1)
    {
        printf("Socket Error");
        exit(EXIT_FAILURE);
    }

    // init sockaddr
    struct sockaddr_in addrServer;
    addrServer.sin_family = AF_INET;
    addrServer.sin_addr.s_addr = htonl(INADDR_ANY);
    // addrServer.sin_addr.s_addr = inet_addr("127.0.0.1");

    addrServer.sin_port = htons(PORT);

    printf("binding..\n");

    if (bind(socketServer, (struct sockaddr *)&addrServer, sizeof(addrServer)) < 0)
    {
        perror("bind()");
        exit(EXIT_FAILURE);
    }
    listen(socketServer, 10);

    printf("server ON\n");

    while (1)
    {
        struct sockaddr *addrclient;
        socklen_t s = sizeof(addrclient);

        int socket_client = accept(socketServer, addrclient, &s);
        if (socket_client < 0)
        {
            perror("accept() ");
        }
        

    }
    

    return 0;
}
