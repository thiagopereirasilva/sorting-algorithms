#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>

#define REPETITION 20
#define SIZE 10000
#define CUTOFF 2

void insertion(int A[], int min, int max) {
//printf("*");
    int i, j, key;
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
//Perceba que existe uma limitação neste algoritmo quanto ao intervalo de representação do
//número inteiro.
void merge(int A[], int min, int half, int max) {
    int n1, n2, *L, *R, i, j, k;
    n1 = half-min;
    n2 = max-half;
    L = malloc(sizeof(int) * (n1+1) );
    R = malloc(sizeof(int) * (n2+1) );

    for(i=0; i<=n1; i++)
        L[i] = A[min+i];

    for(j=0; j<=n2; j++)
        R[j] = A[half+j];

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    i=0, j=0;
    for(k=min; k<max; k++){
        if(L[i] < R[j]) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
    }
    free(L); free(R);
}

void intercala2 (int p, int q, int r, int v[])
{
   int i, j, *w;
   w = malloc ((r-p) * sizeof (int));

   for (i = p; i < q; ++i) w[i-p] = v[i];
   for (j = q; j < r; ++j) w[r-p+q-j-1] = v[j];
       i = 0; j = r-p-1;
   for (int k = p; k < r; ++k)
      if (w[i] <= w[j]) v[k] = w[i++];
      else v[k] = w[j--];
   free (w);
}

void hybrid_merge_sort(int A[], int min, int max, int cutoff) {
   // printf("merge");
    int half;
    if(min < max-1) {
        if(max-min <= cutoff)
            insertion(A, min, max-1);
        else {
            half = (min+max)/2;

            hybrid_merge_sort(A, min, half, cutoff);
            hybrid_merge_sort(A, half, max, cutoff);
            merge(A, min, half, max);             
	    //intercala2(min, half, max, A);
        }
    }
}


/** original
    if(max-min < cutoff)
        insertion(A, min, max-1);
    else if(min < max-1) {
         half = (min+max)/2;

         hybrid_merge_sort(A, min, half, cutoff);
         hybrid_merge_sort(A, half, max, cutoff);
         merge(A, min, half, max);
    }
}
**/
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
    printf("HYBRID MERGE SORT (Size=%d, rept=%d, cutoff=%d)\n", SIZE, REPETITION, CUTOFF);
    for(i=0; i<REPETITION; i++) {
        //vet = orderNumbers(SIZE);
        vet = readNumbers("random_numbers.txt", SIZE);
        //vet = reverseOrderNumbers(SIZE);

        begin = clock();
        hybrid_merge_sort(vet, 0, SIZE, CUTOFF);
        end = clock();

        time_spent = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
        printf("%.f\n", time_spent);
        free(vet);
     }
     /**
    int A[] = {5, 2, -4, 7, 1, 3, 2, 6}, j, k;
    //primeira posição e tamanho do vetor
    hybrid_merge_sort(A, 0, 8, CUTOFF);
    for (j=0; j<8; j++){
        printf("%d ", A[j]);
    }


    int B[100];
    for (j=0, k=100; j<100; j++){
        B[j] = k--;
    }
    printf("\n");
    hybrid_merge_sort(B, 0, 100, CUTOFF);
    for (j=0, k=100; j<100; j++){
        printf("%d ", B[j]);
    }

    return 0;
    **/
}
