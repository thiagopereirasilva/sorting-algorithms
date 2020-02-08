package algoritmos;

import java.io.File;
import java.io.FileNotFoundException;
import java.lang.reflect.Array;
import java.util.Scanner;
import java.util.Vector;
import java.util.concurrent.TimeUnit;

public class QuickSort {

	public void exchange(int[] A, int i, int j){
		int aux = A[i];
		A[i] = A[j];
		A[j] = aux;
	}

	public int partition(int[] A, int p, int r){
		int x = A[r];
		int i = p-1, aux;
		for (int j = p; j <= r-1; j++) {
			if(A[j] <= x) {
				i++;
				aux = A[i];
				A[i] = A[j];
				A[j] = aux;
				//exchange(A, i, j);
				
			}
		}
		//exchange(A, i+1, r);
//novo exchange
		 aux = A[i+1];
		A[r] = A[i+1];
		A[i+1] = aux;
		return i+1;
	}

	public void quickSort(int[] A, int p, int r){
		if(p<r){
			int q = partition(A, p, r);
			quickSort(A, p, q-1);
			quickSort(A, q+1, r);
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
		//s.close();
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
		int SIZE = 100000, REPETITION = 20;
		int[] vet;
		QuickSort qs;

		System.out.printf("QUICK SORT (Size=%d, rept=%d) ORDER\n", SIZE, REPETITION);
		for (i = 0; i < REPETITION; i++) {
			//vet = readNumbers("random_numbers.txt", SIZE);
			vet = order(SIZE);
			qs = new QuickSort();

			begin = System.nanoTime();
			qs.quickSort(vet, 0, vet.length-1);
			end = System.nanoTime();

			System.out.println(TimeUnit.MILLISECONDS.convert(end - begin, TimeUnit.NANOSECONDS));
		}
	}
}
