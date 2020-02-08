package algoritmos;

import java.io.File;
import java.io.FileNotFoundException;
import java.lang.reflect.Array;
import java.util.Scanner;
import java.util.Vector;
import java.util.concurrent.TimeUnit;

public class InsertionSort {

	public void insertionSort(int[] A, int min, int max) {
		for (int j = 1; j <= max; j++) {
			int key = A[j];
			int i = j - 1;
			while ((i >= 0) && (A[i] > key)) {
				A[i + 1] = A[i];
				i--;
			}
			A[i + 1] = key;
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
		InsertionSort is;

		System.out.printf("INSERTION SORT (Size=%d, rept=%d) REVERSE ORDER\n", SIZE, REPETITION);
		for (i = 0; i < REPETITION; i++) {
			//vet = readNumbers("random_numbers.txt", SIZE);
			vet = reverseOrder(SIZE);
			is = new InsertionSort();

			begin = System.nanoTime();
			is.insertionSort(vet, 0, vet.length-1);
			end = System.nanoTime();

			System.out.println(TimeUnit.MILLISECONDS.convert(end - begin, TimeUnit.NANOSECONDS));
		}

		/**
		 * System.out.println("Array inicial: "); for (int i = 0; i < a.length; i++) {
		 * System.out.print(a[i]); } System.out.println();
		 *
		 * is.insertionSort(a, 0, a.length-1);
		 *
		 * System.out.println("Array ordenado com InsertionSort: "); for (int j = 0; j <
		 * a.length; j++) { System.out.print(a[j]); }
		 **/
	}
}
