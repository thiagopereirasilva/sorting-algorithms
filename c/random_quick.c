#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>

#define REPETITION 22
#define SIZE 1000000

// More about functions rand() srand()
//https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/
int randQ(int min, int max) {
    srand(time(0));
    int number = (rand() % (max - min+1)) + min;
    return number;
}

void exchange(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int randomized_partition(int A[], int min, int max) {
    int i = randQ(min, max);
    exchange(&A[i], &A[max]);
  //  printf("rand ");
    return partition(A, min, max);
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

void randomized_quicksort(int A[], int min, int max) {
    if(min < max) {
        int q = randomized_partition(A, min, max);
        randomized_quicksort(A, min , q-1);
        randomized_quicksort(A, q+1 , max);
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
    printf("RANDOM QUICK SORT (Size=%d, rept=%d) Order=%c\n", qtd, REPETITION, order);
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
        randomized_quicksort(vet, 0, qtd-1);
        end = clock();

        time_spent = ((double)(end - begin) / CLOCKS_PER_SEC) * 1000;
        printf("%.f\n", time_spent);
        free(vet);
     }
}
int main() {
//    execute(10000, 'F');
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
    printf("RANDOM QUICK SORT (Size=%d, rept=%d)\n", SIZE, REPETITION);
    for(i=0; i<REPETITION; i++) {
        vet = readNumbers("random_numbers.txt", SIZE);

        begin = clock();
        randomized_quicksort(vet, 0, SIZE-1);
        end = clock();

        time_spent = ((double)(end - begin) / CLOCKS_PER_SEC) * 1000;
        printf("%.f\n", time_spent);
        free(vet);
     }
**/

/**
    int A[] = {5, 2, 4, 7, 1, 3, 2, 6}, j, k;
    //Posição inicial e final
    randomized_quicksort(A, 0, 7);
    for (j=0; j<8; j++){
        printf("%d ", A[j]);
    }


    int B[100];
    for (j=0, k=100; j<100; j++){
        B[j] = k--;
    }
    printf("\n");
    randomized_quicksort(B, 0, 99);
    for (j=0, k=100; j<100; j++){
        printf("%d ", B[j]);
    }
**/
    return 0;
}
