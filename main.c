#include <stdio.h>
#include <stdlib.h>
#include "TP3 Funciones.h"
#define TAM 15


int main()
{
    EMovie movie[TAM];
    char seguir='s';
    int i;

    for (i=0; i<TAM; i++)
    {
        movie[i].puntaje = 0;
    }

    do
    {
        switch(menu())
        {
        case '1':
            inicializarPeliculas(movie,10);
            agregarPelicula(movie);
            break;
        case '2':
            borrarPelicula(movie,10);
            break;
        case '3':
            modificarPelicula(movie,10);
            break;
        }
    }
    while (seguir == 's');
    printf("\n");
    system("pause");
    return 0;
}
