#include <stdio.h>
#include <stdlib.h>

typedef struct {
     int legajo;
     char nombreYapellido [30];
     int edad;
     int anio;
} stAlumno;

void cargarAlFinalArchivo(FILE *archivo);
void mostrarArchivo(FILE *archivo, stAlumno persona[], int validos);
int cargarAlumnos(FILE *archivo, stAlumno persona[], int dim);

int main()
{
   stAlumno persona[20];
   int validos;
   FILE *archivo;

   validos = cargarAlumnos(archivo, persona, 20);
    mostrarArchivo(archivo, persona, validos);
}

void cargarAlFinalArchivo(FILE *archivo){

        archivo = fopen("miArchivo.bin", "ab");

}

void mostrarArchivo(FILE *archivo, stAlumno persona[], int validos){

    int i = 0;

    archivo = fopen("miArchivo.bin", "ab");
    if(archivo != NULL){

       while(i < validos){

        printf("Legajo del Alumno: %d\n", persona[i].legajo);
        printf("Nombre del Alumno: %d\n", persona[i].nombreYapellido);
        printf("Edad del Alumno: %d\n", persona[i].edad);
        printf("Anio del Alumno: %d\n"), persona[i].anio;

       }
    }

}

int cargarAlumnos(FILE *archivo, stAlumno persona[], int dim){

    int i = 0;

    archivo = fopen("miArchivo.bin", "ab");

    if(archivo != NULL){

        while(i < dim){

            printf("Ingresa el legajo del alumno: ");
            fflush(stdin);
            scanf("%i", persona[i].legajo);

             printf("Ingresa el nombre del alumno: ");
            fflush(stdin);
            scanf("%s", persona[i].nombreYapellido);

             printf("Ingresa la edad del alumno: ");
            fflush(stdin);
            scanf("%i", persona[i].edad);

             printf("Ingresa el año del alumno: ");
            fflush(stdin);
            scanf("%i", persona[i].anio);

            i++;
        }
    }

    return i;
}
