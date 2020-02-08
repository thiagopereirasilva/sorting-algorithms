#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>

#define RAND_MAX  INT_MAX

// Generate random integer numbers
// How to execute this program?
// ./PROGRAM LOWER UPPER QUANTITY FILE
// which LOWER is the program's name, LOWER and UPPER are the limits,
// QUANTY is the number of generated numbers, and FILE is the file's name

// Ex. ./random 1 1000 10000 numbers.txt
int main(int argc, char **argv) {
    int min, max, i, number, qtd;
    time_t t;
    FILE *f;

    if(argc != 5) {
        printf("Unexpected number of arguments.\n Ex. ./random 1 1000 10000 numbers.txt");
        return -1;
    }

    min = atoi(argv[1]);
    max = atoi(argv[2]);
    qtd = atoi(argv[3]);
    char *file = argv[4];
/**
    min = INT_MIN+1;
    max = INT_MAX-2;
    qtd = 1000000;
    char *file = "num.txt";
**/
    f = fopen(file, "w+");
    srand((unsigned) time(&t));
    for( i = 0 ; i < qtd ; i++ ) {
        number = (rand() % (max - min+1)) + min;
      //  number = rand() - (RAND_MAX/2);
        fprintf(f, "%d\n", number);
    }

    fclose(f);
    return 0;
}
