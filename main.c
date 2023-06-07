#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

typedef struct
{
    int legajo;
    char nombreYapellido[30];
    int edad;
    int anio;
} stAlumno;

const int dim = 30;

void cargarAlFinalArchivo();
void mostrarArchivo();
int cantidadDeAlumnos();
void cargarAlumnos5();
void mostrarArchivoMod();
void modMostrar(stAlumno persona);
void cargarUnaVez();
int edadEspecifica(stAlumno persona);
void mostrarRangoEdad(stAlumno persona);
void rangoEdad(stAlumno persona, int min, int max);
void mayorEdad(stAlumno persona);
void encontrarMayor (stAlumno persona);
int anioEspecifica(stAlumno persona, int anio);
int pasarArregloAlumnos(stAlumno alumnos[],int dim, stAlumno persona);
void mostrarArreglo(stAlumno arreglo[], int validos);
void catorce (stAlumno persona, int numero);
void modificarAlumno(int numRegistro);
stAlumno alterarAlumno(stAlumno persona);

int main()
{
    Pila pila1;
    inicpila(&pila1);
    stAlumno persona;
    stAlumno alumnos[30];
    int cantAlumnos = 0;
    int cantMayores = 0;
    int anioCant = 0;
    int min;
    int max;
    int anio;
    int dim = 30;
    int validos;
    int numero;


    printf("*** TRABAJO PRACTICO ARCHIVOS ***");


    /* printf("\n\n *PUNTO 1: \n");
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
     mostrarRangoEdad(persona);

     printf("\n\n");

      printf(" *PUNTO 10: \n");
      mayorEdad(persona);

     printf(" *PUNTO 11: \n");

     printf("Ingresa el año de la cursada: ");
     fflush(stdin);
     scanf("%d", &anio);

     anioCant = anioEspecifica(persona, anio);
     printf("La cantidad de alumnos en ese año es: %d", anioCant);

    printf(" *PUNTO 12: \n");
    validos = pasarArregloAlumnos(alumnos, dim, persona);
    mostrarArreglo(alumnos, validos);

    printf("\nPUNTO 14: \n");

    printf("Ingresa un numero entre el 0 y 9: ");
    fflush(stdin);
    scanf("%i", &numero);

    catorce(persona, numero);*/

    printf("PUNTO 15: \n");
    
    modificarAlumno(2);
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
    archivo = fopen("miArchivo.bin", "ab");

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

            printf("Presione 's' para ingresar otro usuario");
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

    if(archivo != NULL)
    {

        while(!feof(archivo))
        {

            fread(&persona, sizeof(stAlumno),1, archivo);

            if(persona.edad > edad)
            {

                cant = cant + 1;

            }
        }

        fclose(archivo);
    }

    return cant;
}

void mostrarRangoEdad(stAlumno persona)
{

    FILE *archivo;

    archivo = fopen("miArchivo.bin", "rb");


    if(archivo != NULL)
    {

        int min,max;

        printf("Ingresa el minimo de edad: ");
        fflush(stdin);
        scanf("%i", &min);

        printf("Ingresa el maximo de edad: ");
        fflush(stdin);
        scanf("%i", &max);


        while(!feof(archivo))
        {

            fread(&persona, sizeof(stAlumno),1, archivo);
            rangoEdad(persona,min,max);

        }

        fclose(archivo);
    }
}

void rangoEdad(stAlumno persona,int min, int max)
{
    FILE *archivo;
    archivo = fopen("miArchivo.bin", "rb");

    if(archivo != NULL)
    {

        if (persona.edad >= min && persona.edad <= max)
        {

            modMostrar(persona);

        }
    }
}

void mayorEdad(stAlumno persona)
{

    FILE *archivo;

    archivo = fopen("miArchivo.bin", "rb");
    stAlumno edadMayor;
    if(archivo != NULL)
    {

        encontrarMayor(persona);

    }
}


void encontrarMayor (stAlumno persona)
{

    FILE *archivo;
    archivo = fopen("miArchivo.bin", "rb");

    stAlumno mayor;

    if(archivo != NULL)
    {

        fread(&mayor, sizeof(stAlumno), 1, archivo);

        while(!feof(archivo))
        {

            fread(&persona, sizeof(stAlumno), 1, archivo);

            if(mayor.edad < persona.edad)
            {

                mayor = persona;

            }
        }
        printf("El alumno con mas edad es: \n");
        modMostrar(mayor);
    }
}

int anioEspecifica(stAlumno persona, int anio)
{

    FILE *archivo;

    archivo = fopen("miArchivo.bin", "rb");

    int cant = 0;

    if(archivo != NULL)
    {

        while(!feof(archivo))
        {

            fread(&persona, sizeof(stAlumno),1, archivo);

            if(persona.anio == anio)
            {

                cant = cant + 1;

            }
        }

        fclose(archivo);
    }

    return cant;
}

int pasarArregloAlumnos(stAlumno alumnos[],int dim, stAlumno persona)
{

    FILE *archivo;
    archivo = fopen("miArchivo.bin", "rb");

    int i = 0;

    if(archivo != NULL)
    {

        while(!feof(archivo))
        {
            fread(&persona, sizeof(stAlumno),1, archivo);

            alumnos[i] = persona;

            i++;
        }
        fclose(archivo);
    }
    return i;
}

void mostrarArreglo(stAlumno arreglo[], int validos)
{

    int i = 0;

    for(i = 0; i < validos; i++)
    {

        printf("\nLegajo: %i\n", arreglo[i].legajo);
        printf("Nombre: %s\n", arreglo[i].nombreYapellido);
        printf("Edad: %i\n", arreglo[i].edad);
        printf("Anio: %i\n", arreglo[i].anio);
        printf("======================");

    }
}

void catorce (stAlumno persona, int numero)
{

    FILE *archivo;
    archivo = fopen("miArchivo.bin", "rb");

    if(archivo != NULL)
    {

        int cant = cantidadDeAlumnos();
        printf("%d", cant);

        if(cant >= 10)
        {
            while(!feof(archivo))
            {
                fread(&persona, sizeof(stAlumno), 1, archivo);
                if(!feof(archivo))
                {
                    if(numero == persona.legajo)
                    {

                        printf("===================");
                        printf("\nLegajo: %d", persona.legajo);
                        printf("\nNombre: %s", persona.nombreYapellido);
                        printf("\nEdad: %d", persona.edad);
                        printf("\nAnio: %d\n", persona.anio);
                        printf("===================");

                    }


                }

            }
        }
        else
        {

            printf("No se llego a la cantidad minima de alumnos :c");

        }

        fclose(archivo);
    }
}

void modificarAlumno(int numRegistro){

    FILE *archivo;
    archivo = fopen("miArchivo.bin", "r+b");
    stAlumno persona;

    if(archivo != NULL)
    {
        fseek(archivo,sizeof(stAlumno) * (numRegistro-1),SEEK_SET);
        fread(&persona,sizeof(stAlumno),1,archivo);
        printf("persona1 antes===================");
                        printf("\nLegajo: %d", persona.legajo);
                        printf("\nNombre: %s", persona.nombreYapellido);
                        printf("\nEdad: %d", persona.edad);
                        printf("\nAnio: %d\n", persona.anio);
                        printf("===================");
        persona = alterarAlumno(persona);
        printf("persona1===================");
                        printf("\nLegajo: %d", persona.legajo);
                        printf("\nNombre: %s", persona.nombreYapellido);
                        printf("\nEdad: %d", persona.edad);
                        printf("\nAnio: %d\n", persona.anio);
                        printf("===================");
        fseek(archivo,sizeof(stAlumno) * -1, SEEK_CUR);
        fwrite(&persona,sizeof(stAlumno),1,archivo);

        fclose(archivo);
    }
}

stAlumno alterarAlumno(stAlumno persona){

    int opc;
    stAlumno cambiar;

    printf("1) Cambiar legajo\n 2)Cambiar Nombre\n 3)Cambiar edad\n 4)Cambiar año\n 5) CAMBIAR TODO\n\n Insertar: ");
    fflush(stdin);
    scanf("%i", &opc);

    switch(opc)
    {

    case 1:

        printf("Ingresa el nuevo legajo: ");
        fflush(stdin);
        scanf("%i", &persona.legajo);

        break;


    case 2:

        printf("Ingresa el nuevo nombre: ");
        fflush(stdin);
        gets(persona.nombreYapellido);

        break;


    case 3:

        printf("Ingresa la nueva edad: ");
        fflush(stdin);
        gets(persona.edad);

        break;


    case 4:

        printf("Ingresa el nuevo año: ");
        fflush(stdin);
        scanf("%i", &persona.anio);

        break;


    case 5:

        printf("Ingresa el nuevo legajo: ");
        fflush(stdin);
        scanf("%i", &persona.legajo);

        printf("Ingresa el nuevo nombre: ");
        fflush(stdin);
        gets(&persona.nombreYapellido);

        printf("Ingresa la nueva edad: ");
        fflush(stdin);
        gets(&persona.edad);

        printf("Ingresa el nuevo año: ");
        fflush(stdin);
        gets(&persona.anio);

        break;

    }
    return persona;
}

