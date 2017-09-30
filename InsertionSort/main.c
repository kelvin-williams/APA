#include <stdio.h>
#include <time.h>


// ALuno: Kelvin Williams Neves Bernardo - 11500272
//
// Insertion Sort

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

//Chamada do Insertion Sort

	start = clock();
    InsertionSort(&arr[0], size);

	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;


    printf("\nInsertion Sort Completo\n\n");
	printf("Tempo de Execução %f segundo(s).\n\n", cpu_time_used);
    printf("Array Ordenado: {");

    for(i = 0; i < size; i++)
            printf("%d ", arr[i]);

    printf("}\n");

}