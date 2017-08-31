#include <stdio.h>

// ALuno: Kelvin Williams Neves Bernardo - 11500272
//
// Heap Sort

#define ARRAY_SIZE 10

void heapify(int * arr, int n, int i){
    int maior = i;  // Toma o primeiro elemento como sendo o maior
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    // Troca se o filho da esquerda é maior que o atual "maior"
    if (l < n && *(arr+l) > *(arr+maior))
        maior = l;
 
    // Troca se o filho da direita for maior que o atual "maior"
    if (r < n && *(arr+r) > *(arr+maior))
        maior = r;
 
    // Se o "maior" não for a raiz da sub-árvore faz a troca
    if (maior != i)
    {
        int aux = *(arr+maior);
        *(arr+maior) = *(arr+i);
        *(arr+i) = aux;
 
        // Continua montando o heap recursivamente
        heapify(arr, n, maior);
    }
}

void HeapSort(int * arr, int size){

    int i;
    // Constrói o heap
    for (i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);
 
    // Remove do Heap um elemento por vez
    for (i=size-1; i>=0; i--)
    {
        // Troca a raiz com o ultimo elemento
        int aux = *arr;
        *arr = *(arr+i);
        *(arr+i) = aux;
         
        // Reorganiza o heap
        heapify(arr, i, 0);
    }


}


void main(){

    int arr[ARRAY_SIZE] = {33,15,99,4,1024,58,621,1,8025,84};
    int i;

    printf("\nArray Inicial: {");
    for(i = 0; i < ARRAY_SIZE; i++)
            printf("%d ", arr[i]);
    
    printf("}\n");

//Chamada do Heap Sort

    HeapSort(&arr[0], ARRAY_SIZE);


    printf("\nHeap Sort Completo\n\n");
    printf("Array Ordenado: {");

    for(i = 0; i < ARRAY_SIZE; i++)
            printf("%d ", arr[i]);

    printf("}\n");

}