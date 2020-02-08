import time

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

def left(i):
    if(i==0):
        return 1
    else:
        return 2*i

def right(i):
    if(i==0):
        return 2
    else:
        return (2*i)+1

def MAX_HEAPIFY(A, i, size):
    l = r = largest = 0
    l = left(i)
    r = right(i)

    #left child greather than
    if(l < size and A[l]>A[i]):
        largest = l
    else:
        largest = i

    if(r < size and A[r] > A[largest]):
        largest = r

    if(largest != i):
        aux = A[i]
        A[i] = A[largest]
        A[largest] = aux
        MAX_HEAPIFY(A, largest, size)

def BUILD_MAX_HEAP(A, size):
    i = (size -1)//2
    while i>=0:
        MAX_HEAPIFY(A, i, size)
        i-=1

def heapsort(A, size):
    BUILD_MAX_HEAP(A, size)
    i = aux = 0
    i = size-1
    while i>0 :
        #exchange
        aux = A[0]
        A[0] = A[i]
        A[i] = aux

        size-=1
        MAX_HEAPIFY(A, 0, --size)
        i-=1

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
SIZE = 10000
vet = []
print("HEAP SORT (Size=" + str(SIZE) + ", rept="+ str(REPETITION) + ")")
for x in range(REPETITION):
    #vet = readNumbers("random_numbers.txt", SIZE)
    vet = reverseOrderNumbers(SIZE)
    
    begin = int(round(time.time() * 1000))
    heapsort(vet, len(vet))
    end = int(round(time.time() * 1000))
    print end-begin

"""print ("Sorted array is:") 
for i in range(len(vet)):
    print ("%d" %vet[i])
"""
