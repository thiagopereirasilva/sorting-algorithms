package algoritmos;

import java.io.File;
import java.io.FileNotFoundException;
import java.lang.reflect.Array;
import java.util.Scanner;
import java.util.Vector;
import java.util.concurrent.TimeUnit;
import java.util.Random;

public class HybridRandomQuickSort {

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

    int randQ(int min, int max) {
        Random randomGenerator = new Random();
        int number = randomGenerator.nextInt(max-min) + min;
        return number;
    }

	public void exchange(int[] A, int i, int j){
		int aux = A[i];
		A[i] = A[j];
		A[j] = aux;
	}

	public int randomized_partition(int[] A, int p, int r){
        int i = randQ(p, r);
        exchange(A, i, r);
        return partition(A, p, r);
	}

	public int partition(int[] A, int p, int r){
		int x = A[r];
		int i = p-1;
		for (int j = p; j <= r-1; j++) {
			if(A[j]<=x){
				i++;
				exchange(A, i, j);
			}
		}
		exchange(A, i+1, r);
		return i+1;
	}

	public void quickSort(int[] A, int p, int r, int cutoff){
		if(p<r){
            if (r-p <= cutoff)
                insertionSort(A, p, r);
            else {
                int q = randomized_partition(A, p, r);
                quickSort(A, p, q-1, cutoff);
                quickSort(A, q+1, r, cutoff);
            }
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

	public static void main(String[] args) {
        long begin, end, i;
		int SIZE = 20, REPETITION = 22, CUTOFF=5;
		int[] vet;
		HybridRandomQuickSort hqs;

		System.out.printf("HYBRID RANDOM QUICK SORT (Size=%d, rept=%d)\n", SIZE, REPETITION);
		for (i = 0; i < REPETITION; i++) {
			vet = readNumbers("random_numbers.txt", SIZE);
			hqs = new HybridRandomQuickSort();

			begin = System.nanoTime();
			hqs.quickSort(vet, 0, vet.length-1, CUTOFF);
			end = System.nanoTime();

			System.out.println(TimeUnit.MILLISECONDS.convert(end - begin, TimeUnit.NANOSECONDS));

		/**	for(int ii=0; ii<SIZE; ii++)
                System.out.println(vet[ii]);
		**/
		}
	}
}
