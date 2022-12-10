#include <sys/socket.h>
#include <arpa/inet.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <threads.h>

#include "../include/struct.h"

int socketServer;
char server_message[2000], client_message[2000];
int isExit;

int OnConnectedServer(void *data)
{
    int quit = 0;
    

    while (quit != 1)
    {

        if ( recv(socketServer, server_message, sizeof(server_message), 0) <= 0 )
        {
            quit = 1;
        }

        printf("%s", server_message);
        memset(server_message, '\0', sizeof(server_message));
    }

    printf("server unreachable \n");
    exit(EXIT_FAILURE);

    return thrd_success;
}

int main(void)
{
    thrd_t onConCl;

    isExit =0;

    memset(server_message, '\0', sizeof(server_message));
    memset(client_message, '\0', sizeof(client_message));

    char ipAddr[20];

    // printf("Ip address (ex : '192.168.1.5') : ");
    // fgets(ipAddr, sizeof(client_message), stdin);
    // printf("\n");

    socketServer = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addrClient;
    addrClient.sin_family = AF_INET;
    addrClient.sin_addr.s_addr = inet_addr("127.0.0.1");
    addrClient.sin_port = htons(PORT);

    if (connect(socketServer, (const struct sockaddr *)&addrClient, sizeof(addrClient)) != 0)
    {
        fprintf(stderr, "error while connecting.\n");
        exit(EXIT_FAILURE);
    }

    if (thrd_create(&onConCl, OnConnectedServer, NULL) != thrd_success)
    {
        fprintf(stderr, "Erreur lors de la creation du thread");
        exit(EXIT_FAILURE);
    }

    // recv(socketServer, &server_message, sizeof(server_message), 0);

    while (isExit != 1)
    {

        memset(client_message, '\0', sizeof(client_message));

        fgets(client_message, sizeof(client_message), stdin);

        if ( send(socketServer, (void *)client_message, sizeof(client_message), 0) < 0)
        {
            printf("an error occured when sending your message\n ");
        }
    }

    return 0;
}