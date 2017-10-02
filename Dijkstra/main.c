#include <stdio.h>

// ALuno: Kelvin Williams Neves Bernardo - 11500272
//
// Dijkstra's Algorithm

void heapify(int * arr, int n, int i){
    int menor = i;  // Toma o primeiro elemento como sendo o menor
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    // Troca se o filho da esquerda é menor que o atual "menor"
    if (l < n && arr[l] < arr[menor])
        menor = l;
 
    // Troca se o filho da direita for menor que o atual "menor"
    if (r < n && arr[r] < arr[menor])
        menor = r;
 
    // Se o "menor" não for a raiz da sub-árvore faz a troca
    if (menor != i)
    {
        int aux = arr[menor];
        arr[menor] = arr[i];
        arr[i] = aux;
 
        // Continua Consertando o heap
        heapify(arr, n, menor);
    }
}

void BuildMinHeap(int * heap, int size){
    int i;
    for (i = size / 2 - 1; i >= 0; i--)
        heapify(heap, size, i);
}

int HeapExtMin(int * heap, int * size){
    int min = heap[0];

    heap[0] = heap[*(size) -1];
    *size = *size-1;

    heapify(heap, *size, 0);
    return min;
}