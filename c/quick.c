#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>

#define REPETITION 20
#define SIZE 10000

void exchange(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int partition(int A[], int min, int max) {
    int x, i, j;
    x = A[max];
    i = min-1;
    for(j=min; j<max; j++) {
        if(A[j] <= x) {
            i++;
            exchange(&A[i], &A[j]);
        }
    }
    exchange(&A[i+1], &A[max]);
    return i+1;
}

void quicksort(int A[], int min, int max) {
    if(min < max) {
        int q = partition(A, min, max);
        quicksort(A, min , q-1);
        quicksort(A, q+1 , max);
    }
}

int * readNumbers(char *file, int size) {
    int i=0, aux,*vet = malloc(sizeof(int) * size);
    FILE *f = fopen(file, "r");
    while(EOF!=fscanf(f, "%d", &aux) && i<size)
        vet[i++] = aux;
    fclose(f);
    return vet;
}

int * orderNumbers(int size) {
    int i=0, aux, *vet = malloc(sizeof(int) * size);
    while(i<size) {
        vet[i] = i++;
    }
    return vet;
}

int * reverseOrderNumbers(int size) {
    int i=0, aux=size, *vet = malloc(sizeof(int) * size);
    while(i<size){
        vet[i++] = aux--;
    }
    return vet;
}

void execute(int qtd, char order) {
    int i=0, *vet;
    double time_spent;
    clock_t end, begin;
    printf("QUICK SORT (Size=%d, rept=%d) Order=%c\n", qtd, REPETITION, order);
    for(i=0; i<REPETITION; i++) {
	if(order == 'R')
		vet = reverseOrderNumbers(qtd);
	else if(order == 'O')
		vet = orderNumbers(qtd);
	else if(order == 'F')
		vet = readNumbers("random_numbers.txt", qtd);
	else
		return;

        begin = clock();
        quicksort(vet, 0, qtd-1);
        end = clock();

        time_spent = ((double)(end - begin) / CLOCKS_PER_SEC) * 1000;
        printf("%.f\n", time_spent);
        free(vet);
     }
}
int main() {
//    execute(10000, 'R');
//    execute(100000, 'R');
//    execute(200000, 'R');
   // execute(1000000, 'O');
   // execute(200000, 'O');
   // execute(200000, 'F');
    execute(1000000, 'O');

/**
    int i=0, *vet;
    double time_spent;
    clock_t end, begin;
    printf("QUICK SORT (Size=%d, rept=%d)\n", SIZE, REPETITION);
    for(i=0; i<REPETITION; i++) {
        vet = readNumbers("random_numbers.txt", SIZE);

        begin = clock();
        quicksort(vet, 0, SIZE-1);
        end = clock();

        time_spent = ((double)(end - begin) / CLOCKS_PER_SEC) * 1000;
        printf("%.f\n", time_spent);
        free(vet);
     }
**/
    /**
    int B[100];
    for (j=0, k=100; j<100; j++){
        B[j] = k--;
    }
    printf("\n");
    quicksort(B, 0, 99);
    for (j=0, k=100; j<100; j++){
        printf("%d ", B[j]);
    }
    **/
    return 0;
}
