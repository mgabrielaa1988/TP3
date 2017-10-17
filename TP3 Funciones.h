#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char titulo[100];
    char genero[100];
    int duracion;
    char descripcion[100];
    int puntaje;
    char linkImagen[200];
} EMovie;

void toString(EMovie*);

char menu(void);

void inicializarPeliculas(EMovie movie[],int tam);

void agregarPelicula(EMovie*);

int newMovie(EMovie*,char[],char[],int,char[],int,char[]);

void borrarPelicula(EMovie*,int);

void modificarPelicula(EMovie*,int);

void generarPagina(EMovie lista[], char nombre[]);

#endif // FUNCIONES_H_INCLUDED

