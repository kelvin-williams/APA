#include <stdio.h>
#include <time.h>

// ALuno: Kelvin Williams Neves Bernardo - 11500272
//
// Heap Sort

int countfile(char * str, int * max){
    FILE *f; 
    f = fopen(str, "r");
    int size = 0;
    int aux;

    while(!feof (f))
    {                
        fscanf(f, "%d", &aux);
        size++;
        if(aux > *max)
            *max = aux;
    }
    fclose(f);

    return size;
}

void GetNumbersfromFile(char * str, int * arr){

    FILE *f; 
    f = fopen(str, "r");
    int i = 0;

    while(!feof (f))
    {                
        fscanf(f, "%d", arr+i);
        i++;
    }
    fclose(f);
}


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

    clock_t start, end;
    double cpu_time_used;
    int max = 0;

    int size = countfile("instancias-num/num.100000.1.in", &max);

    printf("\nTamanho do Array: %d, Valor Maximo: %d \n\n", size, max);

    int arr[size];
    int i;

    GetNumbersfromFile("instancias-num/num.100000.1.in", &arr[0]);

    printf("\nArray Inicial: {");
    for(i = 0; i < size; i++)
            printf("%d ", arr[i]);
    
    printf("}\n");

//Chamada do Heap Sort

	start = clock();

    HeapSort(&arr[0], size);

	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nHeap Sort Completo\n\n");
	printf("Tempo de Execução %f segundo(s).\n\n", cpu_time_used);
    printf("Array Ordenado: {");

    for(i = 0; i < size; i++)
            printf("%d ", arr[i]);

    printf("}\n");

}