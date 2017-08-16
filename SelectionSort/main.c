#include <stdio.h>

// ALuno: Kelvin Williams Neves Bernardo - 11500272
//
// Selection Sort

#define ARRAY_SIZE 10

void SelectionSort(int * arr, int size){

    int a, b, menor;

    for(a = 0; a < size-1; a++){//Percorre o array completo

        menor = a;//Inicia marcando o primeiro elemento como sendo o menor

        for(b = a+1; b < size -1;  b++){

                if(*(arr+b) < *(arr+menor))
                    menor = b;

        }

        if(menor != a){//Faz a troca
            int aux = *(arr+a);
            *(arr+a) = *(arr+menor);
            *(arr+menor) = aux;
        }

    }

}


void main(){

    int arr[ARRAY_SIZE] = {6,2,9,5,8,1,4,0,7,3};
    int i;

    printf("\nArray Inicial: {");
    for(i = 0; i < ARRAY_SIZE - 1; i++)
            printf("%d ", arr[i]);
    
    printf("}\n");

    SelectionSort(&arr[0], ARRAY_SIZE);
    printf("\nSelection Sort Completo\n\n");
    printf("Array Ordenado: {");

    for(i = 0; i < ARRAY_SIZE - 1; i++)
            printf("%d ", arr[i]);

    printf("}\n");

    return 0;

}