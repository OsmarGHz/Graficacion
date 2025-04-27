#include <stdio.h>

int determinePD(int i, int j){
    int pd;
    pd = ((i*(i+1))/2) + j;
    return pd;
}

int main(){
    int msi[10] = {1,2,3,4,5,6,7,8,9,10};
    int i,j;
    printf("Esta es la matriz triangular: \n");
    for (i = 0; i < 4; i++){
        for (j = 0; j <= i; j++){
            printf("%i ",msi[determinePD(i,j)]);
        }
        printf("\n");
    }
    printf("\n");
    for (i = 3; i >= 0; i--){
        for (j = 0; j <= i; j++){
            printf("El PD de la posicion (%i,%i) de la matriz triangular es: %i\n",i,j,determinePD(i,j));
        }
    }
    
}