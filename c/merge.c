#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>

#define REPETITION 22
#define SIZE 1000000

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

void merge_sort(int A[], int min, int max) {
    int half;
    if(min < max-1) {
        half = (min+max)/2;
        merge_sort(A, min, half);
        merge_sort(A, half, max);
        merge(A, min, half, max);
       //intercala2(min, half, max, A);
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

int isSorted(int *vet, int size){
    int i=0;
    while(i<size-1) {
        if (vet[i] > vet[++i])
            return 0;
    }
    return 1;
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

void execute(int qtd) {
    double result[22][3];
    int i=0, *vet;
    double time_spent;
    clock_t end, begin;
    printf("MERGE SORT (Size=%d, rept=%d)\n", qtd, REPETITION);
    //order numbers
    for(i=0; i<REPETITION; i++) {
       // printf("Order\n");
        vet = orderNumbers(qtd);

        begin = clock();
        merge_sort(vet, 0, qtd);
        end = clock();

        time_spent = ((double)(end - begin) / CLOCKS_PER_SEC) * 1000;
        //printf("%.f\n", time_spent);
        result[i][0] = time_spent;
        free(vet);
    }
    //Random numbers
    for(i=0; i<REPETITION; i++) {
       // printf("Random numbers\n");
   		vet = readNumbers("random_numbers.txt", qtd);

        begin = clock();
        merge_sort(vet, 0, qtd);
        end = clock();

        time_spent = ((double)(end - begin) / CLOCKS_PER_SEC) * 1000;
        result[i][1] = time_spent;
        free(vet);
    }
    //Reverse order numbers
    for(i=0; i<REPETITION; i++) {
       // printf("Reverse Order\n");
   		vet = reverseOrderNumbers(qtd);

        begin = clock();
        merge_sort(vet, 0, qtd);
        end = clock();

        time_spent = ((double)(end - begin) / CLOCKS_PER_SEC) * 1000;
        result[i][2] = time_spent;
        free(vet);
     }
     printResults(result);
}

void printResults(double results[22][3]) {
    int i, j;
    for(j=0; j<22; j++)
         printf("%.f\t%.f\t%.f\n", results[j][0], results[j][1], results[j][2]);
}

int main() {
    execute(100000);
    return 0;
}
