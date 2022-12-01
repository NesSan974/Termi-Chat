//------------------------------------------------
// INCLUDES
//------------------------------------------------
#include <sys/socket.h>=
#include <arpa/inet.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <threads.h>

#include "../include/struct.h"
#include "../include/List.h"

//------------------------------------------------
// GLOBALS
//------------------------------------------------

// variable pour la connection socket
int socketServer;

// all client connected
List *allClient;

//------------------------------------------------
// THREAD FUNCTION
//------------------------------------------------

int OnConnectedClient(void *data)
{
    struct SocketThreads *socketThreads = malloc(sizeof(struct SocketThreads));
    socketThreads->socketClient = ((struct SocketThreads *)data)->socketClient;

    allClient = AddtoList(allClient, 0, (void *)&socketThreads->socketClient);

    // Init message
    memset(socketThreads->server_message, '\0', sizeof(socketThreads->server_message));
    memset(socketThreads->client_message, '\0', sizeof(socketThreads->client_message));

    int quit = 0;

    while (quit != 1)
    {

        if (recv(socketThreads->socketClient, socketThreads->client_message, sizeof(socketThreads->client_message), 0) <= 0)
        {
            quit = 1;
        }

        int i = 0;
        while (i < GetLenghtList(allClient))
        {
            int a = *(int *)GetElemInList(allClient, i);

            if (socketThreads->socketClient != a)
            {
                send(a, (void *)socketThreads->client_message, sizeof(socketThreads->client_message), 0);
            }
            i++;
        }

        memset(socketThreads->client_message, '\0', sizeof(socketThreads->client_message));
    }

    printf("%d\n", GetLenghtList(allClient));

    printf("fin threads : %d\n", socketThreads->socketClient);

    int i = -1;
    int find = 0;

    int sc = socketThreads->socketClient;

    while (i < GetLenghtList(allClient) - 1 && find != 1)
    {
        i++;

        int a = *(int *)GetElemInList(allClient, i);
        if (a == sc)
        {
            find = 1;
        }
    }

    printf("end \n");

    DeleteElemInList(allClient, i);
    free(socketThreads);

    return thrd_success;
}

//------------------------------------------------
// MAIN FUNCTION
//------------------------------------------------

int main(void)
{
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

    if (bind(socketServer, (const struct sockaddr *)&addrServer, sizeof(addrServer)) < 0)
    {
        perror("bind()");
        exit(EXIT_FAILURE);
    }

    printf("server ON\n");
    listen(socketServer, 10);

    int i = 0;
    while (1 == 1)
    {
        struct SocketThreads *st;

        socklen_t sizeClient = sizeof(struct sockaddr_in);

        // Accept est une boucle qui attend la co d'un client
        st->socketClient = accept(socketServer, (struct sockaddr *)&st->addrClient, &sizeClient);

        if (st->socketClient < 0)
        {
            perror("accept() ");
            exit(EXIT_FAILURE);
        }

        printf("connexion du client %d\n", st->socketClient);

        if (thrd_create(&onConCl, OnConnectedClient, (void *)st) != thrd_success)
        {
            fprintf(stderr, "Erreur lors de la creation du thread");
            exit(EXIT_FAILURE);
        }
        i++;
    }
    printf("wtf\n");
    char ch;
    scanf("%c", &ch);

    shutdown(socketServer, SHUT_RDWR);

    return 0;
}