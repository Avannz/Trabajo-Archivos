#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

typedef struct
{
    int legajo;
    char nombreYapellido[30];
    int edad;
    int anio;
} stAlumno;

void cargarAlFinalArchivo();
void mostrarArchivo();
int cantidadDeAlumnos();
void cargarAlumnos5();
void mostrarArchivoMod();
void modMostrar(stAlumno persona);
void cargarUnaVez();
int edadEspecifica(stAlumno persona);

int main()
{
    Pila pila1;
    inicpila(&pila1);
    stAlumno persona;
    int cantAlumnos = 0;
    int cantMayores = 0;


    printf("*** TRABAJO PRACTICO ARCHIVOS ***");


    printf("\n\n *PUNTO 1: \n");
    cargarAlFinalArchivo();

    printf("\n\n");

    printf(" *PUNTO 2: \n");
    mostrarArchivo();

    printf("\n\n");

    printf(" *PUNTO 3: \n");
    cantAlumnos = cantidadDeAlumnos();
    printf("\n- La cantidad de alumnos registrados es de: %d ", cantAlumnos);

    printf("\n\n");

    printf("\n *PUNTO 4: \n");
    cargarAlumnos5();

    printf("\n\n");

    printf(" *PUNTO 5: \n");
    mostrarArchivoMod();

    printf("\n\n");

    printf(" *PUNTO 6: \n");
    cargarUnaVez();

    printf("\n\n");

    printf(" *PUNTO 7: \n");
    cargarPilaMayores(&pila1, persona);
    mostrar(&pila1);

    printf("\n\n");

    printf(" *PUNTO 8: \n");
    cantMayores = edadEspecifica(persona);
    printf("La cantidad de alumnos mayores a la edad ingresada es de: %d", cantMayores);

    printf("\n\n");

    printf(" *PUNTO 9: \n");
}

void cargarAlFinalArchivo()
{

    FILE *archivo;
    archivo = fopen("miArchivo.bin", "ab");

    if(archivo != NULL)
    {

        stAlumno persona;

        printf("Ingresa el legajo del alumno: ");
        scanf("%i", &persona.legajo);

        printf("Ingresa el nombre del alumno: ");
        fflush(stdin);
        gets(&persona.nombreYapellido);

        printf("Ingresa la edad del alumno: ");
        scanf("%i", &persona.edad);

        printf("Ingresa el anio del alumno: ");
        scanf("%i", &persona.anio);

        fwrite(&persona, sizeof(stAlumno),1, archivo);

        fclose(archivo);
    }
}

void mostrarArchivo()
{

    FILE *archivo;
    archivo = fopen("miArchivo.bin", "rb");
    stAlumno persona;

    if(archivo != NULL)
    {

        while(!feof(archivo))
        {

            fread(&persona, sizeof(stAlumno),1, archivo);

            if(!feof(archivo))
            {
                printf("===================");
                printf("\nLegajo: %d", persona.legajo);
                printf("\nNombre: %s", persona.nombreYapellido);
                printf("\nEdad: %d", persona.edad);
                printf("\nAnio: %d\n", persona.anio);
                printf("===================");
            }
        }
        fclose(archivo);
    }
}

int cantidadDeAlumnos()
{
    FILE *archivo;
    archivo = fopen("miArchivo.bin", "rb");
    int cant = 0;
    if(archivo != NULL)
    {

        fseek(archivo,0,SEEK_END); //VOY AL FINAL DEL ARCHIVO Y ME MUEVO 0 VECES
        long int totalArchivo = ftell(archivo); // FTELL ME ENVIA LA CANT EN BITS DE LO QUE OCUPA MI ARCHIVO
        cant = (int)totalArchivo/sizeof(stAlumno); // CANT DE BITS % PESO DE LA VARIABLE

        fclose(archivo);
    }

    return cant;
}

void cargarAlumnos5()
{

    FILE *archivo;
    archivo = fopen("miArchivo.bin", "wb");

    if (archivo != NULL)
    {

        printf("\nEl archivo ya estaba creado previamente\n");

        int i = 0;

        while(i < 5)
        {
            cargarAlFinalArchivo();
            i++;
        }
        fclose(archivo);
    }
    else
    {
        printf("\nEl archivo es inexistente\n");
        archivo = fopen("miArchivo.bin", "wb");
    }
}

void mostrarArchivoMod()
{

    FILE *archivo;
    archivo = fopen("miArchivo.bin", "rb");

    if(archivo != NULL)
    {

        stAlumno persona;

        while(!feof(archivo))
        {

            fread(&persona, sizeof(stAlumno),1, archivo);

            if(!feof(archivo))
            {

                modMostrar(persona);

            }
        }
        fclose(archivo);

    }

}

void modMostrar(stAlumno persona)
{
    printf("\n===================\n");
    printf("Legajo: %d", persona.legajo);
    printf("\nNombre: %s", persona.nombreYapellido);
    printf("\nEdad: %d", persona.edad);
    printf("\nAnio: %d\n", persona.anio);
    printf("\n===================\n");
}

void cargarUnaVez()
{

    FILE *archivo;
    char letra = 's';
    archivo = fopen("miArchivo.bin", "ab");

    if(archivo != NULL)
    {

        while(letra == 's')
        {

            cargarAlFinalArchivo();

            printf("Presione 's' para ingresar otro usuario: ");
            fflush(stdin);
            scanf("%c", &letra);
        }
    }
}

void cargarPilaMayores(Pila *pila1, stAlumno persona)
{

    FILE *archivo;

    archivo = fopen("miArchivo.bin", "rb");

    int mayor = 18;

    if(archivo != NULL)
    {

        while(!feof(archivo))
        {

            fread(&persona,sizeof(stAlumno),1,archivo);

            if(persona.edad >= mayor)
            {
                apilar(pila1, persona.legajo);
            }
        }

        fclose(archivo);
    }
}

int edadEspecifica(stAlumno persona)
{

    FILE *archivo;

    archivo = fopen("miArchivo.bin", "rb");

    int edad;
    int cant = 0;

    printf("Ingresa el filtro de edad: ");
    fflush(stdin);
    scanf("%d", &edad);

    if(archivo != NULL){

        while(!feof(archivo)){

            fread(&persona, sizeof(stAlumno),1 , archivo);

            if(persona.edad > edad){

                cant = cant + 1;

            }
        }

        fclose(archivo);
    }

    return cant;
}
