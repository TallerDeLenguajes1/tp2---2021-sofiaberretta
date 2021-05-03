#include <stdio.h>
#include <stdlib.h>
#define Filas 15

int main(){

    int Columnas, i, j, h, num, pares = 0;
    Columnas = rand () % (15-5+1) + 5; // Numero random de columnas entre 5 y 15

    int matriz[Filas][Columnas];
    int vector[Filas]; //Vector formado por numeros pares de la matriz

    printf("####### MATRIZ ######\n \n");
    for(i=0; i < Filas; i++)
    {
        for (j = 0; j < Columnas; j++)
        {
            num = rand () % (999-100+1) + 100; //Numero random entre 100 y 999
            matriz[i][j]= num; //Le asigno a mi matriz

            if(matriz[i][j] % 2 == 0){ //Me fijo si ese numero es par
                pares++;
            }

            printf("%d ", matriz[i][j]); //Muestro el elemento
        }

        printf("\n La cantidad de numeros pares de la fila %d son: %d \n", i, pares); //Muestro la cantidad de pares de la fila

        vector[i]= pares; // Le asigno la cantidad de pares por cada fila a cada elemento del vector
        
        pares=0; // Reinicio el contador de pares cuando termina la fila

        printf("\n");
    }

    printf("####### VECTOR ######\n");
    for(h=0; h < Filas; h++){
        printf("%d ", vector[h]); // Muestro el vector
    }

}