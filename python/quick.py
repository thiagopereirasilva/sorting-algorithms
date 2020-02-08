import time
import sys

def readNumbers(file, size):
    vet = []
    i = 0
    f = open(file, "r")
    for line in f:
        if i > size:
            break
        vet.append(int(line))
        i = i+1
    f.close()
    return vet

def quicksort(A, min, max):
    if min < max:
        q = partition(A, min, max)
        quicksort(A, min , q-1)
        quicksort(A, q+1 , max)

def partition(A, min, max):
    x = i = j = aux = 0
    x = A[max]
    i = min-1
    for j in range(min, max):
        if(A[j] <= x):
            i+=1
            #exchange(&A[i], &A[j]);
            aux = A[i]
            A[i] = A[j]
            A[j] = aux
    #exchange A[i+1], A[max]
    aux = A[i+1]
    A[i+1] = A[max]
    A[max] = aux
    return i+1

def orderNumbers(size):
    i = 0
    vet = []
    while i<size:
        vet.append(i)
        i+=1
    return vet

def reverseOrderNumbers(size):
    i = 0
    vet = []
    while size>0 :
        vet.append(size)
        size-=1
    return vet;

# main
REPETITION = 20
SIZE = 50000
vet = []
sys.setrecursionlimit(99999999)
print("QUICK SORT (Size=" + str(SIZE) + ", rept="+ str(REPETITION) + ")")
for x in range(REPETITION):
    #vet = readNumbers("random_numbers.txt", SIZE)
    vet = orderNumbers(SIZE)
    
    begin = int(round(time.time() * 1000))
    quicksort(vet, 0, len(vet)-1)
    end = int(round(time.time() * 1000))

    print (end-begin)

"""print ("Sorted array is:")
for i in range(len(vet)):
    print ("%d" %vet[i])
"""
