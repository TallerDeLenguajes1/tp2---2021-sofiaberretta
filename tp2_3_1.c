#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct computadora
{
    int velocidad; //entre 1 y 3 Gherz
    int anio; //entre 2000 y 2017
    char *tipo_cpu; //valores del arreglo tipos
    int cantNucleos; //entre 1 y 4
} PC;


PC devuelvePC(PC estructura, char *tipos);
void cargarPC(PC *arreglo, int cantidad, char *tipos);
void mostrar(PC *arreglo, int indice);
int masVieja(PC *arreglo, int tamanio);
int masRapida(PC *arreglo, int tamanio);

int main(){

    srand(time(NULL));

    char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    int cant, vieja, rapida;
    PC *arregloPC;

    // funcion que devuelve una PC pasando la estructura

    PC compu = devuelvePC(compu, &tipos[0][0]);
    printf("\nLas caracteristicas de la PC son: \n");
    mostrar(&compu, 0);
    free(compu.tipo_cpu);

    // funcion a la que se le pasa puntero y carga las pcs
    printf("\n\nIngrese la cantidad de computadoras: ");
    scanf("%d", &cant);

    arregloPC = (PC *)malloc(sizeof(PC)* cant);

    cargarPC(arregloPC, cant, &tipos[0][0]);

    //funcion que muestra
    for(int i = 0; i < cant; i++){
    
        mostrar(arregloPC, i);
    }

    //pc mas vieja
    printf("\n -------------------------------");
    vieja = masVieja(arregloPC, cant);
    printf("\n La pc mas vieja es la numero %d, del anio %d", vieja + 1, (arregloPC + vieja)->anio);

    //pc mas rapida 
    printf("\n -------------------------------");
    rapida = masRapida(arregloPC, cant);
    printf("\n La pc mas rapida es la numero %d, con una velocidad de %d GHz", rapida + 1, (arregloPC + rapida)->velocidad);

}

PC devuelvePC(PC estructura, char *tipos)
{
    int tipoRand;
    estructura.velocidad = rand () % 3 + 1; 
    estructura.anio = rand () % 17 + 2000;
    estructura.cantNucleos = rand () % 4 + 1;

    tipoRand = rand () % 6;
    estructura.tipo_cpu = (char*)malloc(sizeof(char)*10);
    strcpy(estructura.tipo_cpu, (tipos + (tipoRand*10))); //por que

    return estructura;
}

void cargarPC(PC *arreglo, int cantidad, char *tipos)
{
    int i, tipoRand;

    for (i = 0; i < cantidad; i++)
    {
        (arreglo + i)->velocidad = rand () % 3 + 1; 
        (arreglo + i)->anio = rand () % 17 + 2000;
        (arreglo + i)->cantNucleos = rand () % 4 + 1;

        tipoRand = rand () % 6;
        (arreglo + i)->tipo_cpu = (char*)malloc(sizeof(char)*10);
        strcpy((arreglo + i)->tipo_cpu, (tipos + (tipoRand*10)));
    }
}

void mostrar(PC *arreglo, int indice)
{
    printf("\n #### COMPUTADORA N %d ####", indice+1);

    printf("\n Velocidad de procesamiento en GHz: %d", (arreglo + indice)->velocidad); 
    printf("\n Anio de fabricacion: %d", (arreglo + indice)->anio);
    printf("\n Tipo de procesador: %s", (arreglo + indice)->tipo_cpu);
    printf("\n Cantidad de nucleos: %d", (arreglo + indice)->cantNucleos);
    printf("\n");
}

int masVieja(PC *arreglo, int tamanio)
{
    int min = 4000;
    int numPC;

    for (int i = 0; i < tamanio; i++)
    {
        if (((arreglo + i)->anio) < min)
        {
            min = (arreglo + i)->anio;
            numPC = i;
        }
        
    }

    return numPC;
    
}

int masRapida(PC *arreglo, int tamanio)
{
    int min = 0;
    int numPC;

    for (int i = 0; i < tamanio; i++)
    {
        if ((arreglo + i)->velocidad > min)
        {
            min = (arreglo + i)->velocidad;
            numPC = i;
        }
        
    }

    return numPC;
}