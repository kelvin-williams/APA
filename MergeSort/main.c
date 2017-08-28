#include <stdio.h>

// ALuno: Kelvin Williams Neves Bernardo - 11500272
//
// Merge Sort

#define ARRAY_SIZE 10

void MergeSort(int * arr, int st, int end){

   // int aux[end-st + 1];
   // printf("\n %d", end -st + 1);

    if(st < end){

        int aux[end - st + 1];
        int m = (st + end)/2;
        int a = st;
        int b = m+1;
        int i = 0;
        MergeSort(&arr[0], st, m);
        MergeSort(&arr[0], m+1, end);
    
    //Merge
        //for(i = 0; i <= (end - st); i++){
          while(a <= m && b < end+1){

            if(*(arr+a) <= *(arr+b)){
                *(aux+i) = *(arr+a);
                a++;
                i++;
            }else{
                *(aux+i) = *(arr+b);
                b++;
                i++;
            }
        }

        while(a <= m){
            *(aux+i) = *(arr+a);
            a++;
            i++;
        }

        while(b < end+1){
            *(aux+i) = *(arr+b);
            b++;
            i++;
        }

        for(i = st; i <= end; i++){
        *(arr+i) = *(aux+ i - st);
        }


    }
}


void main(){

    int arr[ARRAY_SIZE] = {9,36,90,63,45,72,81,54,18,27};
    int aux[ARRAY_SIZE];
    int i;

    printf("\nArray Inicial: {");
    for(i = 0; i < ARRAY_SIZE; i++)
            printf("%d ", arr[i]);
    
    printf("}\n");

//Chamada do Merge Sort

    MergeSort(&arr[0], 0, ARRAY_SIZE-1);


    printf("\nMerge Sort Completo\n\n");
    printf("Array Ordenado: {");

    for(i = 0; i < ARRAY_SIZE; i++)
            printf("%d ", arr[i]);

    printf("}\n");

}