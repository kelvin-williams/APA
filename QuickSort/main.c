#include <stdio.h>

// ALuno: Kelvin Williams Neves Bernardo - 11500272
//
// Quick Sort

#define ARRAY_SIZE 10

void QuickSort(int * arr, int min, int max){

    int pivo = *(arr+(min + max)/2);
    int a = min;
    int b = max;

    while(a<=b){
        //Anda com "a" até encontrar um valor maior que o pivô
        while((*(arr+a) < pivo) && (a < max)){
            a++;
        }
        //Anda com "b" até encontrar um valor menor que o pivô
        while((*(arr+b) > pivo) && (b > min)){
            b--;
        }

        if(a<=b){//Faz a troca de lado entre dois elementos
            int aux = *(arr+a);
            *(arr+a) = *(arr+b);
            *(arr+b) = aux;
            a++;
            b--;
        }
    }
    
    if(b > min){
        QuickSort(arr, min, b);
    }

    if(a < max){
        QuickSort(arr, a, max);
    }

    

}


void main(){

    int arr[ARRAY_SIZE] = {29,112,3,54,30,48,107,66,901,52};
    int i;

    printf("\nArray Inicial: {");
    for(i = 0; i < ARRAY_SIZE; i++)
            printf("%d ", arr[i]);
    
    printf("}\n");

//Chamada do Quick Sort

    QuickSort(&arr[0], 0, ARRAY_SIZE-1);


    printf("\nQuick Sort Completo\n\n");
    printf("Array Ordenado: {");

    for(i = 0; i < ARRAY_SIZE; i++)
            printf("%d ", arr[i]);

    printf("}\n");

}