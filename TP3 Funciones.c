#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include "TP3 Funciones.h"

void inicializarPeliculas(EMovie movie[],int tam)
{
    char titulo[][100]= {"Avatar","Titanic","Star Wars: Episode VII - The Force Awakens","Jurassic World","The Avengers","Furious 7","Avengers: Age of Ultron","Harry Potter y las Reliquias de la Muerte - Parte 2","Frozen","La Bella y la Bestia"};
    char genero[][100]= {"Ciencia ficcion, Aventura, Accion, Fantastico","Romance, Catastrofe, Drama","Space opera, Epico","Ciencia ficcion, Aventuras, Terror, Accion","Accion, Aventuras, Ciencia ficcion, Superheroes","Accion, Aventuras, Crimen, Romance, Suspenso, Drama","Accion, Aventuras, Ciencia ficcion, Superheroes","Accion, Fantasia, Aventuras","Animacion, Comedia, Aventuras, Drama, Musical, Fantasia, Romance","Drama, Fantasia, Musical, Romance"};
    int duracion[]= {162,195,136,124,142,140,142,130,102,129};
    char descripcion[][200]= {"Unos cientificos descubren la aldea de los pitufos y un hombre se somete a una cirugia para irse a vivir con ellos","Una abuelita le cuenta a su nieta la vez que se acosto con un vagabundo y luego lo mato","Un emo trata de matar a la joven de la basura todo porque su papa no le ponia la atencion que el queria","El tipo de Guardianes de la Galaxia da de comer a un pescado un costosisimo dinosaurio","Un grupo de supermodelos salva la Tierra del ex novio de Taylor Swift","Un grupo de ladrones y un hombre hecho por computadora tendran que unirse para pelear contra el tipo del transportador","Los mismos modelos se enfrentan a Ultron","Un niño llega a la pubertad y descubre las cosas que puede haer con su varita","Una mujer aterroriza a todo un pueblo porque su hermana menor se va a casar antes que ella","Todos huyen del feo del pueblo pero una chica descubre que es millonario y ese mismo dia se va a vivir con el"};
    int puntaje[]= {7, 7, 7, 6, 7, 6, 6, 7, 6, 7};
    char linkImagen[][100]= {};
    int i;

    for (i=0; i<tam; i++)
    {
        strcpy(movie[i].titulo,titulo);
        strcpy(movie[i].genero,genero);
        movie[i].duracion = duracion;
        strcpy(movie[i].descripcion,descripcion);
        movie[i].puntaje = puntaje;
        strcpy(movie[i].linkImagen,linkImagen);
    }
}

char menu()
{
    char c;
    system("cls");
    printf("--------MENU--------\n");
    printf("  1- Agregar pelicula\n");
    printf("  2- Borrar pelicula\n");
    printf("  3- Modificar pelicula\n");
    printf("  4- Generar pagina web\n");
    printf("  5- Salir\n");
    printf("  Elija una opcion: ");
    c = getche();
    return c;
}

void agregarPelicula(EMovie* movie)
{
    char titulo[100];
    char genero[100];
    int duracion;
    char descripcion[200];
    int puntaje;
    char linkImagen[100];

    printf("  Ingrese los datos de la nueva pelicula\n");
    printf("  Titulo: \n");
    fflush(stdin);
    gets(titulo);
    printf("  Genero: \n");
    fflush(stdin);
    gets(genero);
    printf("  Duracion: \n");
    scanf("%d",&duracion);
    printf("  Descripcion: \n");
    fflush(stdin);
    gets(descripcion);
    printf("  Puntaje: \n");
    scanf("%d",&puntaje);
    printf("  Link a imagen: \n");
    fflush(stdin);
    gets(linkImagen);

    if(newMovie(movie,titulo,genero,duracion,descripcion,puntaje,linkImagen))
    {
        printf("  Pelicula agregada!");
    }
    else
    {
        printf("  ERROR... carga de datos fallida");
    }
}

int newMovie(EMovie* nMovie,char titulo[],char genero[],int duracion,char descripcion[],int puntaje,char link[])
{
    int retorno = 0;

    if(nMovie!=NULL)
    {
        strcpy(nMovie->titulo,titulo);
        strcpy(nMovie->genero,genero);
        nMovie->duracion = duracion;
        strcpy(nMovie->descripcion,descripcion);
        nMovie->puntaje = puntaje;
        strcpy(nMovie->linkImagen,link);
        retorno = 1;
    }
    return retorno;
}

void toString(EMovie* movie)
{
    printf("%s\t\t%s\t\t%d\t\t%s\t\t%d\t\t%s\n",movie->titulo,movie->genero,movie->duracion,movie->descripcion,movie->puntaje,movie->linkImagen);
}

void borrarPelicula(EMovie* movie,int tam)
{
    char auxTitulo[100];
    char opcion;
    int i;
    int flag =0;
    printf("  Ingrese el titulo de la pelicula que desea eliminar: \n");
    fflush(stdin);
    gets(auxTitulo);

    for (i=0; i<tam; i++)
    {
        if(strcmp(movie->titulo,auxTitulo)==0)
        {
            printf("  Pelicula a eliminar: \n");
            toString((movie + i));
            printf("  Confirma eliminar pelicula: \n");
            opcion = getche();

            if (opcion == 's')
            {
                movie[i].puntaje = 0;
                printf("  Pelicula borrada!\n");
            }
            else
            {
                printf("  La pelicula no fue eliminada\n");
            }
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("  Pelicula inexistente");
    }
}

void modificarPelicula(EMovie* movie, int tam)
{
    char auxTitulo[100];
    char opcion;
    int i;
    int flag = 0;
    char auxGenero[100];
    int auxDuracion;
    char auxDescripcion[200];
    int auxPuntaje;
    char auxLink[100];

    printf("  Ingrese el titulo de la pelicula que desea modificar: \n");
    fflush(stdin);
    gets(auxTitulo);

    for (i=0; i<tam; i++)
    {
        if(strcmp(movie->titulo,auxTitulo)==0)
        {
            printf("  Pelicula encontrada:\n");
            toString((movie + i));

            printf("  Desea modificar el genero?");
            opcion = getche();
            if (opcion == 's')
            {
                printf("  Ingrese nuevo genero:\n");
                fflush(stdin);
                gets(auxGenero);
                strcpy(movie[i].genero,auxGenero);
            }
            else
            {
                printf("  El genero no fue modificado");
            }

            printf("  Desea modificar la duracion?");
            opcion = getche();
            if (opcion == 's')
            {
                printf("  Ingrese nueva duracion:\n");
                scanf("%d",auxDuracion);
                movie[i].duracion=auxDuracion;
            }
            else
            {
                printf("  La duracion no fue modificada");
            }

            printf("  Desea modificar la descripcion?");
            opcion = getche();
            if (opcion == 's')
            {
                printf("  Ingrese nueva descripcion:\n");
                fflush(stdin);
                gets(auxDescripcion);
                strcpy(movie[i].descripcion,auxDescripcion);
            }
            else
            {
                printf("  La descripcion no fue modificada");
            }

            printf("  Desea modificar el puntaje?");
            if (opcion == 's')
            {
                printf("  Ingrese nuevo puntaje:\n");
                scanf("%d",auxPuntaje);
                movie[i].puntaje = auxPuntaje;
            }
            else
            {
                printf("  La duracion no fue modificada");
            }

            printf("  Desea modificar el link a la imagen?");
            opcion = getche();
            if (opcion == 's')
            {
                printf("  Ingrese nuevo link:\n");
                fflush(stdin);
                gets(auxLink);
                strcpy(movie[i].linkImagen,auxLink);
            }
            else
            {
                printf("  El link no fue modificado");
            }
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("  Pelicula inexistente");
    }
}

void generarPagina(EMovie lista[], char nombre[])
{

}

