// store messages using a service

#include "client.h"

int sock;
char* host;

int main(int argc, char *argv[])
{
    char* m;
    
    if(argc != 3) {
        fprintf(stderr, "Uso: %s <host> <mensaje>\n", argv[0]);
        exit(1);
    }
    
    host = argv[1];
    m = argv[2];
    
    sock = connection(); // conexipon con el servidor para llamar servicios
    
    int result = store(m); // llamada local (servicio store)
    
    printf ("Resultado recibido por el cliente: %d\n", result);
    printf ("El mensaje fue almacenado\n");
    
    close(sock);
    return 0;
}
