#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define REPETITION 22
#define SIZE 10000
void insertion(int A[], int min, int max)
{
    int i, j, key;
    for (j=1; j<=max; j++)
    {
        key = A[j];
        i = j-1;
        while(i>=0 && A[i]>key)
        {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}

int * readNumbers(char *file, int size)
{
    int i=0, aux,*vet = malloc(sizeof(int) * size);

    FILE *f = fopen(file, "r");
    while(EOF!=fscanf(f, "%d", &aux) && i<size)
        vet[i++] = aux;
    fclose(f);
    return vet;
}


int * orderNumbers(int size)
{
    int i=0, aux, *vet = malloc(sizeof(int) * size);
    while(i<size)
    {
        vet[i] = i++;
    }
    return vet;
}

int * reverseOrderNumbers(int size)
{
    int i=0, aux=size, *vet = malloc(sizeof(int) * size);
    while(i<size)
    {
        vet[i++] = aux--;
    }
    return vet;
}

void execute(int qtd, char order)
{
    int i=0, *vet;
    double time_spent;
    clock_t end, begin;
    printf("INSERTION SORT (Size=%d, rept=%d) %c\n", qtd, REPETITION, order);
    for(i=0; i<REPETITION; i++)
    {
        if(order == 'R')
            vet = reverseOrderNumbers(qtd);
        else if(order == 'O')
            vet = orderNumbers(qtd);
        else if(order == 'F')
            vet = readNumbers("random_numbers.txt", qtd);
        else
            return;

        begin = clock();
        insertion(vet, 0, qtd-1);
        end = clock();

        time_spent = ((double)(end - begin) / CLOCKS_PER_SEC) * 1000;
        printf("%.f\n", time_spent);
        free(vet);
    }
}


int main()
{
   // execute(200000, 'O');
   // execute(200000, 'F');
   // execute(200000, 'R');

    //execute(500000, 'O');
    //execute(500000, 'F');
    execute(1000000, 'R');
//    execute(500000, 'R');
//    execute(800000, 'R');
//    execute(1000000, 'R');

    return 0;
}
