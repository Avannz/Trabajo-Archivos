#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    stAlumno persona[20];
    int cantAlumnos;

    /*cargarAlFinalArchivo();
    mostrarArchivo();

    cantAlumnos = cantidadDeAlumnos();
    printf("\nLa cantidad de alumnos registrados es de: %d", cantAlumnos);*/

    cargarAlumnos5();
    mostrarArchivo();
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
                printf("Legajo: %d", persona.legajo);
                printf("\nNombre: %s", persona.nombreYapellido);
                printf("\nEdad: %d", persona.edad);
                printf("\nAnio: %d\n", persona.anio);
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
    archivo = fopen("miArchivo.bin", "rb");

    if (archivo != NULL)
    {

        printf("\nEl archivo ya estaba creado previamente");

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

        printf("\nEl archivo es inexistente");
        archivo = fopen("miArchivo.bin", "wb");
    }
}

void mostrarArchivoMod()
{

    FILE *archivo;
    archivo = fopen("miArchivo.bin", "rb");

    if(archivo != NULL){

    stAlumno persona;

        while(!feof(archivo))
        {

            fread(&persona, sizeof(stAlumno),1, archivo);

            if(!feof(archivo))
            {
                
                modMostrar();
                
            }
        }
        fclose(archivo);

    }

}

void modMostrar()
{

        printf("Legajo: %d", persona.legajo);
                printf("\nNombre: %s", persona.nombreYapellido);
                printf("\nEdad: %d", persona.edad);
                printf("\nAnio: %d\n", persona.anio);
}
