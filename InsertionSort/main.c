#include <stdio.h>

// ALuno: Kelvin Williams Neves Bernardo - 11500272
//
// Insertion Sort

#define ARRAY_SIZE 10

void InsertionSort(int * arr, int size){

    int a, b, key;

    for(a = 1; a < size; a++){

        key = *(arr+a);
        b = a-1;

        while(b >= 0 && *(arr+b)> key){
                *(arr+b+1) = *(arr+b);
                b--;
        }
        *(arr+b+1) = key;

    }


}


void main(){

    int arr[ARRAY_SIZE] = {30,12,98,33,61,2,10,7,102,3};
    int i;

    printf("\nArray Inicial: {");
    for(i = 0; i < ARRAY_SIZE; i++)
            printf("%d ", arr[i]);
    
    printf("}\n");

//Chamada do Insertion Sort

    InsertionSort(&arr[0], ARRAY_SIZE);


    printf("\nInsertion Sort Completo\n\n");
    printf("Array Ordenado: {");

    for(i = 0; i < ARRAY_SIZE; i++)
            printf("%d ", arr[i]);

    printf("}\n");

}