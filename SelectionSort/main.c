#include <stdio.h>
#include <time.h>

// ALuno: Kelvin Williams Neves Bernardo - 11500272
//
// Selection Sort

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


void SelectionSort(int * arr, int size){

    int a, b, menor;

    for(a = 0; a < size-1; a++){//Percorre o array completo

        menor = a;//Inicia marcando o primeiro elemento como sendo o menor

        for(b = a+1; b < size;  b++){

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

	start = clock();

    SelectionSort(&arr[0], size);

	end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nSelection Sort Completo\n\n");
	printf("Tempo de Execução %f segundo(s).\n\n", cpu_time_used);

    printf("Array Ordenado: {");

    for(i = 0; i < size; i++)
            printf("%d ", arr[i]);

    printf("}\n");


}