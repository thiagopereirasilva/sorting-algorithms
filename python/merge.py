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

def merge_sort(arr): 
    if len(arr) >1: 
        mid = len(arr)//2
        L = arr[:mid]
        R = arr[mid:]
  
        merge_sort(L)
        merge_sort(R)
  
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
REPETITION = 22
SIZE = 1000000
vet = []
print("MERGE SORT (Size=" + str(SIZE) + ", rept="+ str(REPETITION) + ")")
for x in range(REPETITION):
    #vet = readNumbers("random_numbers.txt", SIZE)
    vet = reverseOrderNumbers(SIZE)
    
    begin = int(round(time.time() * 1000))
    merge_sort(vet)
    end = int(round(time.time() * 1000))

    print end-begin

"""print ("Sorted array is:") 
for i in range(len(vet)):
    print ("%d" %vet[i])
"""
