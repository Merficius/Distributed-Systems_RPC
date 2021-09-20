
#include "server.h"

char* recv_message(int client_sock);
void send_result(int client_sock, int value);

int main(int argc, char *argv[])
{
    int socket_desc = initialization();
    
    while(1) {
        int client_sock = connection(socket_desc);
        char* m = recv_message(client_sock); // Adaptador del parámatero-> copy-restore
        
        int value = store(m);
        free(m); // Liberamos los recursos utilizados
        
        send_result(client_sock, value); // Adaptador del resultado -> por valor
    }
    
    close(socket_desc);
    return 0;
}

char* recv_message(int client_sock)
{
    char* message;
    int read_size, length;
    
    // receive the message length from client
    read_size = recv(client_sock, &length, sizeof(length), 0);
    
    // Dynamic memory allocation to store the message: little endian
    message = (char*) malloc(length); // Incluye el fin de cadena
    read_size = recv(client_sock, message, length, 0);

    
    if(read_size == 0) {
        puts("Client disconnected");
        fflush(stdout);
    }
    else if(read_size == -1) {
        perror("recv failed");
    }
    
    return message;
}

void send_result(int client_sock, int value)
{
    printf("server_result: %d\n", value);
    
    // send result to the client: little endian
    if(send(client_sock, &value, sizeof(value), 0) < 0)
    {
        puts("send failed");
        exit(1);
    }
}
