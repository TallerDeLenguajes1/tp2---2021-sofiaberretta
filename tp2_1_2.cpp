#include <stdio.h>
#define Filas 4
#define Columnas 5

int main(){

    int i, j;
    double matriz[Filas][Columnas]=
    {
        {1.1, 2.1, 3.1, 4.1, 5.1},
        {1.2, 2.2, 3.2, 4.2, 5.2},
        {1.3, 2.3, 3.3, 4.3, 5.3},
        {1.4, 2.4, 3.4, 4.4, 5.4},
    };
    double *p;

    p = &matriz[0][0];

    for(i=0; i < Filas; i++)
    {
        for (int j = 0; j < Columnas; j++)
        {
            printf("%lf ", *(p + i * Columnas + j));
        }
        printf("\n");
    }
}