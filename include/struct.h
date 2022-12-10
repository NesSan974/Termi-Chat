#ifndef __STRUCT_H__
#define __STRUCT_H__

#define PORT 5255

struct SocketThreads
{
    char server_message[2000], client_message[2000];
    struct sockaddr_in addrClient;
    int socketClient;
};

#endif