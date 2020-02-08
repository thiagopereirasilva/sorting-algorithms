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
  
def hybrid_merge_sort(arr, cutoff):
    if (len(arr) < cutoff):
        insertion(arr)
    else:
        if len(arr) >1: 
            mid = len(arr)//2
            L = arr[:mid]
            R = arr[mid:]
  
            hybrid_merge_sort(L, cutoff)
            hybrid_merge_sort(R, cutoff)
  
            i = j = k = 0          

            while i < len(L) and j < len(R): 
                if L[i] < R[j]: 
                    arr[k] = L[i] 
                    i+=1
                else: 
                    arr[k] = R[j] 
                    j+=1
                k+=1
          
            while i < len(L): 
                arr[k] = L[i] 
                i+=1
                k+=1
          
            while j < len(R): 
                arr[k] = R[j] 
                j+=1
                k+=1

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
vet = []

CUTOFF = 5
print("HYBRID MERGE SORT (Size=" + str(SIZE) + ", rept="+ str(REPETITION) + ", cutoff=" + str(CUTOFF) + ")")
for x in range(REPETITION):
    #vet = readNumbers("random_numbers.txt", SIZE)
    vet = reverseOrderNumbers(SIZE)
    
    begin = int(round(time.time() * 1000))
    hybrid_merge_sort(vet, CUTOFF)
    end = int(round(time.time() * 1000))

    print end-begin

CUTOFF = 10
print("HYBRID MERGE SORT (Size=" + str(SIZE) + ", rept="+ str(REPETITION) + ", cutoff=" + str(CUTOFF) + ")")
for x in range(REPETITION):
#    vet = readNumbers("random_numbers.txt", SIZE)
    vet = reverseOrderNumbers(SIZE)
    
    begin = int(round(time.time() * 1000))
    hybrid_merge_sort(vet, CUTOFF)
    end = int(round(time.time() * 1000))

    print end-begin

CUTOFF = 25
print("HYBRID MERGE SORT (Size=" + str(SIZE) + ", rept="+ str(REPETITION) + ", cutoff=" + str(CUTOFF) + ")")
for x in range(REPETITION):
 #   vet = readNumbers("random_numbers.txt", SIZE)
    vet = reverseOrderNumbers(SIZE)
    
    begin = int(round(time.time() * 1000))
    hybrid_merge_sort(vet, CUTOFF)
    end = int(round(time.time() * 1000))

    print end-begin


CUTOFF = 50
print("HYBRID MERGE SORT (Size=" + str(SIZE) + ", rept="+ str(REPETITION) + ", cutoff=" + str(CUTOFF) + ")")
for x in range(REPETITION):
#    vet = readNumbers("random_numbers.txt", SIZE)
    vet = reverseOrderNumbers(SIZE)
   
    begin = int(round(time.time() * 1000))
    hybrid_merge_sort(vet, CUTOFF)
    end = int(round(time.time() * 1000))

    print end-begin

CUTOFF = 75
print("HYBRID MERGE SORT (Size=" + str(SIZE) + ", rept="+ str(REPETITION) + ", cutoff=" + str(CUTOFF) + ")")
for x in range(REPETITION):
  #  vet = readNumbers("random_numbers.txt", SIZE)
    vet = reverseOrderNumbers(SIZE) 
    begin = int(round(time.time() * 1000))
    hybrid_merge_sort(vet, CUTOFF)
    end = int(round(time.time() * 1000))

    print end-begin

CUTOFF = 100
print("HYBRID MERGE SORT (Size=" + str(SIZE) + ", rept="+ str(REPETITION) + ", cutoff=" + str(CUTOFF) + ")")
for x in range(REPETITION):
    vet = reverseOrderNumbers(SIZE)
    #vet = readNumbers("random_numbers.txt", SIZE)
    
    begin = int(round(time.time() * 1000))
    hybrid_merge_sort(vet, CUTOFF)
    end = int(round(time.time() * 1000))

    print end-begin

CUTOFF = 200
print("HYBRID MERGE SORT (Size=" + str(SIZE) + ", rept="+ str(REPETITION) + ", cutoff=" + str(CUTOFF) + ")")
for x in range(REPETITION):
    vet = reverseOrderNumbers(SIZE)
    #vet = readNumbers("random_numbers.txt", SIZE)
    
    begin = int(round(time.time() * 1000))
    hybrid_merge_sort(vet, CUTOFF)
    end = int(round(time.time() * 1000))

    print end-begin
"""print ("Sorted array is:")
for i in range(len(vet)):
    print ("%d" %vet[i])
"""
