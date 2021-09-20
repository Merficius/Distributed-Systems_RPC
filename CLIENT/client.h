#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT_NUM 8888

// utilities

int connection();
int close(int sock);

// remote service

int store(char* m);
