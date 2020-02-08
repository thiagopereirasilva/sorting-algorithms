package algoritmos;

import java.io.File;
import java.io.FileNotFoundException;
import java.lang.reflect.Array;
import java.util.Scanner;
import java.util.Vector;
import java.util.concurrent.TimeUnit;

public class HeapSort {

	public int left (int i){
		if(i==0){
			return 1;
		}else{
			return 2*i;
		}
	}

	public int right(int i){
		if(i==0){
			return 2;
		}else{
			return (2*i)+1;
		}
	}

	public void max_heapify(int A[], int i, int size){
		int l, r, largest;
		l = left(i);
		r = right(i);

		if((l < size) && (A[l] > A[i])){
			largest = l;
		}else{
			largest = i;
		}

		if((r < size) && (A[r] > A[largest])){
			largest = r;
		}

		if(largest != i){
			int aux = A[i];
			A[i] = A[largest];
			A[largest] = aux;
			max_heapify(A, largest, size);
		}
	}

	public void build_max_heap(int A[], int size){
		for(int i=(size-1)/2; i>=0; i--){
			max_heapify(A, i, size);
		}
	}

	public void exchange(int[] A, int i, int j){
		int aux = A[i];
		A[i] = A[j];
		A[j] = aux;
	}

	public void heapsort(int A[], int size){
		build_max_heap(A, size);
		int aux;
		for(int i = size-1; i>0; i--){
			exchange(A, 0, i);
			max_heapify(A, 0, --size);
		}
	}

	static int[] readNumbers(String file, int size) {
		int i = 0, vet[] = new int[size];
		File f = new File(file);
		Scanner s;
		try {
			s = new Scanner(f);
			while (s.hasNextInt() && i < size) {
				vet[i++] = s.nextInt();
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		return vet;
	}

	static int[] order(int size) {
		int i = 0, vet[] = new int[size];
		while (i < size) {
				vet[i] = i++;
		}
		return vet;
	}

	static int[] reverseOrder(int size) {
		int i = 0, vet[] = new int[size];
		while (size>0) {
				vet[i++] = size--;
		}
		return vet;
	}
	public static void main(String[] args) {
       		long begin, end, i;
		int SIZE = 1000000, REPETITION = 20;
		int[] vet;
		HeapSort hs;

		System.out.printf("HEAP SORT (Size=%d, rept=%d)\n", SIZE, REPETITION);
		for (i = 0; i < REPETITION; i++) {
			//vet = readNumbers("random_numbers.txt", SIZE);
			vet = reverseOrder(SIZE);
			hs = new HeapSort();

			begin = System.nanoTime();
			hs.heapsort(vet, vet.length);
			end = System.nanoTime();

			System.out.println(TimeUnit.MILLISECONDS.convert(end - begin, TimeUnit.NANOSECONDS));
		}
	}
}
