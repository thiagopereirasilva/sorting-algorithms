#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>

#define REPETITION 20
#define SIZE 1000000
#define CUTOFF 500

void insertion(int A[], int min, int max) {
   // printf("inserction (%d - %d)\n", min, max);
    int i, j, key;
    //int length = (max - min) + 1;
    for (j=1; j<=max; j++){
        key = A[j];
        i = j-1;
        while(i>=0 && A[i]>key){
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}


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

int randomized_partition(int A[], int min, int max) {
    int i = randQ(min, max);
    exchange(&A[i], &A[max]);
    return partition(A, min, max);
}

void hybrid_quicksort(int A[], int min, int max, int cutoff) {
    if(min < max) {
        if(max-min+1 > cutoff) {
            int q = randomized_partition(A, min, max); //printf("\tq=%d\n",q);
            hybrid_quicksort(A, min , q-1, cutoff);
            hybrid_quicksort(A, q+1 , max, cutoff);
        }
        else
            insertion(A, min, max);
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
    while(i<size) {
        vet[i++] = aux--;
    }
    return vet;
}

int main() {

    int i=0, t, *vet;
    double time_spent;
    clock_t end, begin;
    printf("HYBRID QUICK SORT (Size=%d, rept=%d, cutoff=%d)\n", SIZE, REPETITION, CUTOFF);

    for(i=0; i<REPETITION; i++) {
	vet = orderNumbers(SIZE);
        //vet = readNumbers("random_numbers.txt", SIZE);
        //vet = reverseOrderNumbers(SIZE);

        begin = clock();
        hybrid_quicksort(vet, 0, SIZE-1, CUTOFF);
        end = clock();

        time_spent = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
        printf("%.f\n", time_spent);
        free(vet);
     }

    /**

    int A[] = {5, 2, 4, 7, 1, 3, 2, 6}, j, k;
    //Posição inicial e final
    hybrid_quicksort(A, 0, 7, CUTOFF);
    for (j=0; j<8; j++){
        printf("%d ", A[j]);
    }


    int B[100];
    for (j=0, k=100; j<100; j++){
        B[j] = k--;
    }
    printf("\n");
    hybrid_quicksort(B, 0, 99, CUTOFF);
    for (j=0, k=100; j<100; j++){
        printf("%d ", B[j]);
    }
**/
    return 0;
}
