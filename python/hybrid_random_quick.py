import time
from random import seed
from random import randint

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

def insertion(A, min, max):  
    # through 1 to len(A)
    #print("Insert - min=" + str(min) + " max=" + str(max))
    for i in range(min+1, max): 
        key = A[i]
        j = i-1
        while j>=0 and key < A[j]: 
                A[j+1] = A[j] 
                j -= 1
        A[j+1] = key
    #for k in range(min, max): 
     #   print(str(A[k])+"---")

def randQ(min, max):
    return randint(min, max)

def hybrid_random_quicksort(A, min, max, cutoff):
    if(min < max):
        if(max-min > cutoff):
            q = randomized_partition(A, min, max)
            hybrid_random_quicksort(A, min, q-1, cutoff)
            hybrid_random_quicksort(A, q+1, max, cutoff)
        else:
            insertion(A, min, max)

def randomized_partition(A, min, max):
    i = randQ(min, max)
    #exchange(&A[i], &A[max]);
    aux = A[i]
    A[i] = A[max]
    A[max] = aux

    return partition(A, min, max)

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
REPETITION = 5
SIZE = 1000000
CUTOFF = 75
vet = []
print("HYBRID RANDOM QUICK SORT (Size=" + str(SIZE) + ", rept="+ str(REPETITION) + " cutoff=" + str(CUTOFF) + ")")
for x in range(REPETITION):
#    vet = orderNumbers(SIZE)
#    vet = readNumbers("random_numbers.txt", SIZE)
    vet = reverseOrderNumbers(SIZE)
    
    begin = int(round(time.time() * 1000))
    hybrid_random_quicksort(vet, 0, len(vet)-1, CUTOFF)
    end = int(round(time.time() * 1000))

    print end-begin

CUTOFF = 100
print("HYBRID RANDOM QUICK SORT (Size=" + str(SIZE) + ", rept="+ str(REPETITION) + " cutoff=" + str(CUTOFF) + ")")
for x in range(REPETITION):
#    vet = orderNumbers(SIZE)
#    vet = readNumbers("random_numbers.txt", SIZE)
    vet = reverseOrderNumbers(SIZE)
    
    begin = int(round(time.time() * 1000))
    hybrid_random_quicksort(vet, 0, len(vet)-1, CUTOFF)
    end = int(round(time.time() * 1000))

    print end-begin

CUTOFF = 200
print("HYBRID RANDOM QUICK SORT (Size=" + str(SIZE) + ", rept="+ str(REPETITION) + " cutoff=" + str(CUTOFF) + ")")
for x in range(REPETITION):
#    vet = orderNumbers(SIZE)
#    vet = readNumbers("random_numbers.txt", SIZE)
    vet = reverseOrderNumbers(SIZE)
    
    begin = int(round(time.time() * 1000))
    hybrid_random_quicksort(vet, 0, len(vet)-1, CUTOFF)
    end = int(round(time.time() * 1000))

    print end-begin

"""print ("Sorted array is:")
for i in range(len(vet)):
    print ("%d" %vet[i])
"""
