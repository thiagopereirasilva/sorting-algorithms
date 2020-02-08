#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>

#define REPETITION 22
#define SIZE 1000000
int left(int i){
    if(i==0)
        return 1;
    else
        return 2*i;
}

int right(int i) {
    if(i==0)
        return 2;
    else
        return (2*i)+1;
}

void MAX_HEAPIFY(int A[], int i, int size) {
    int l, r, largest;
    l = left(i);
    r = right(i);

    //left child greather than
    if(l < size && A[l]>A[i])
        largest = l;
    else
        largest = i;
    if(r < size && A[r] > A[largest])
        largest = r;

    if(largest != i) {
        int aux = A[i];
        A[i] = A[largest];
        A[largest] = aux;
        MAX_HEAPIFY(A, largest, size);
    }
}

void BUILD_MAX_HEAP(int A[], int size) {
    int i;
    for(i=(size-1)/2; i>=0; i--) {
        MAX_HEAPIFY(A, i, size);
    }
}

void exchange(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void heapsort(int A[], int size) {
    BUILD_MAX_HEAP(A, size);
    int i, aux;
    for(i=size-1; i>0; i--) {
        exchange(&A[0], &A[i]);
        MAX_HEAPIFY(A, 0, --size);
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
    printf("HEAP SORT (Size=%d, rept=%d) Order=%c\n", qtd, REPETITION, order);
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
        heapsort(vet, qtd);
        end = clock();

        time_spent = ((double)(end - begin) / CLOCKS_PER_SEC) * 1000;
        printf("%.f\n", time_spent);
        free(vet);
     }
}
int main(){
    execute(10000, 'O');
    execute(100000, 'O');
    execute(200000, 'O');
    execute(500000, 'O');
    execute(800000, 'O');
    execute(1000000, 'O');

/**
    int i=0, *vet;
    double time_spent;
    clock_t end, begin;
    printf("HEAP SORT (Size=%d, rept=%d)\n", SIZE, REPETITION);
    for(i=0; i<REPETITION; i++) {
        vet = readNumbers("random_numbers.txt", SIZE);

        begin = clock();
        heapsort(vet, SIZE);
        end = clock();

        time_spent = ((double)(end - begin) / CLOCKS_PER_SEC) * 1000;
        printf("%.f\n", time_spent);
        free(vet);
     }
**/
/**
    int B[100], j,k;
    for (j=0, k=100; j<100; j++){
        B[j] = k--;
    }
    printf("\n");
    heapsort(B, 100);
    for (j=0, k=100; j<100; j++){
        printf("%d ", B[j]);
    }
**/
    return 0;
}
