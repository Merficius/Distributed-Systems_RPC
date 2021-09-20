
// Almacena mensajes en "mensajes.txt"

/* service.c: Código de la función remota */

#include <stdio.h>
#include <string.h>

// Agrega un nuevo mensaje al archivo: servicio "store"

int store( char * m )
{
    FILE * fp = fopen( "mensajes.txt", "a" );

    fprintf( fp, "%s\n", m );
    fclose( fp );

    return strlen(m);
}

// Podríamos tener varios servicios
