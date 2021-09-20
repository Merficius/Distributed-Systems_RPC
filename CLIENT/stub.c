
#include "client.h"

extern int sock;

int store(char* m)
{
    int read_size, result;
    int length = strlen(m);
    
    // send message m
    send(sock, &length, sizeof(length), 0);
    
    if(send(sock, m, length, 0) < 0)
    {
        puts("Send fails");
        exit(1);
    }
    
    // receive the result from server
    read_size = recv(sock, &result, sizeof(result), 0);
    
    if(read_size == 0)
    {
        puts("Client disconnected");
        fflush(stdout);
    }
    else if(read_size == -1)
    {
        perror("rec failed");
    }
    
    return result;
}
