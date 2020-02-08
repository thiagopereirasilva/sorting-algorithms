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

def insertion(A):  
    # through 1 to len(A) 
    for i in range(1, len(A)): 
        key = A[i] 
        j = i-1
        while j >=0 and key < A[j] : 
                A[j+1] = A[j] 
                j -= 1
        A[j+1] = key 

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
SIZE = 200000
vet = []
print("INSERTION SORT (Size=" + str(SIZE) + ", rept="+ str(REPETITION) + ")")
for x in range(REPETITION):
    vet = reverseOrderNumbers(SIZE)
#readNumbers("random_numbers.txt", SIZE)
    
    
    begin = int(round(time.time() * 1000))
    insertion(vet)
    end = int(round(time.time() * 1000))

    print (end-begin)
#print ("Sorted array is:") 
#for i in range(len(vet)):
#    print ("%d" %vet[i])
