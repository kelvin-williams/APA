#include <stdio.h>
#include <time.h>

// ALuno: Kelvin Williams Neves Bernardo - 11500272
//
// Radix Sort


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

void CountSort2(int * arr,int size, int exp){

    int count[10];
    int brr[size];
    int i, j;
    //Zerando Count
    for(i = 0; i < 10; i++)
        count[i] = 0;

    for(j = 0; j < size; j++)
        ++count[ (arr[j]/exp)%10 ];

    for(i = 1; i < 10; i++)
        count[i] = count[i] + count[i-1];

    for(j = size -1; j >=0; j--){
        brr[count[ (arr[j]/exp)%10 ]-1] = arr[j];
        --count[ (arr[j]/exp)%10 ]; 
    }
    //Copia de volta para o array inicial
    for (i = 0; i < size; i++)
        arr[i] = brr[i];

}

void RadixSort(int * arr, int size, int m){

    int exp;

    for(exp = 1; m/exp > 0; exp = exp*10)
        CountSort2(arr, size, exp);
    
}


void main(){

    clock_t start, end;
    double cpu_time_used;
    int max = 0;

    int size = countfile("counting.txt", &max);

    printf("\nTamanho do Array: %d, Valor Maximo: %d \n\n", size, max);

    int arr[size];
    int i;

    GetNumbersfromFile("counting.txt", &arr[0]);

    printf("\nArray Inicial: {");
    for(i = 0; i < size; i++)
            printf("%d ", arr[i]);
    
    printf("}\n");


    start = clock();

//Chamada do Radix Sort

    RadixSort(&arr[0], size, max);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;


    printf("\nRadix Sort Completo\n\n");
    printf("Tempo de Execução %f segundo(s).\n\n", cpu_time_used);
    printf("Array Ordenado: {");

    for(i = 0; i < size; i++)
            printf("%d ", arr[i]);

    printf("}\n");

}