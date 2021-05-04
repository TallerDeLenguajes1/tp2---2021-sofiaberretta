#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Filas 15

int main(){

    srand(time(NULL));
    int Columnas, i, j, h, num, pares = 0;

    int **matriz;

    matriz = (int **)malloc(sizeof(int*)*Filas);
    Columnas = rand () % (15-5+1) + 5; // Numero random de columnas entre 5 y 15

    int *vector; //Vector formado por numeros pares de la matriz
    vector= (int*)malloc(sizeof(int)*Filas);

    printf("####### MATRIZ ######\n \n");
    for(i=0; i < Filas; i++)
    {
        *(matriz + i) = (int*)malloc(sizeof(int)*Columnas);
        
        for (j = 0; j < Columnas; j++)
        {
            *(*(matriz + i)+ j)= rand () % (999-100+1) + 100;

            if(*(*(matriz + i)+ j) % 2 == 0){ //Me fijo si ese numero es par
                pares++;
            }

            printf("%d ", *(*(matriz + i)+ j)); //Muestro el elemento
        }

        printf("\n La cantidad de numeros pares de la fila %d son: %d \n", i, pares); //Muestro la cantidad de pares de la fila

        *(vector + i)= pares; // Le asigno la cantidad de pares por cada fila a cada elemento del vector
        
        pares=0; // Reinicio el contador de pares cuando termina la fila

        printf("\n");

    }

    printf("####### VECTOR ######\n");
    for(h=0; h < Filas; h++){
        printf("%d ", *(vector + h)); // Muestro el vector
    }

    free(matriz);
    free(vector);

    return 0;

}