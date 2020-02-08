package algoritmos;

import java.io.File;
import java.io.FileNotFoundException;
import java.lang.reflect.Array;
import java.util.Scanner;
import java.util.Vector;
import java.util.concurrent.TimeUnit;

public class HybridMergeSort {

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

	public void merge(int[] a, int min, int half, int max){

		final int n1 = half-min+1;
		final int n2 = max-half;

		final int[]l = new int [n1+1];
		final int[]r = new int [n2+1];

		for (int i=0; i<n1; i++){
			l[i] = a[min + i];
		}

		for (int j=0; j<n2; j++){
			r[j] = a[half + j + 1];
		}

		l[n1] = Integer.MAX_VALUE;
		r[n2] = Integer.MAX_VALUE;

		int i = 0, j = 0;

		for(int f = min; f <= max; f++){
			if(l[i] <= r[j]){
				a[f] = l[i++];
			}else{
				a[f] = r[j++];
			}
		}

	}

	public void mergeSort(int[] a, int min, int max, int cutoff){
		if(max-min <= cutoff)
            insertionSort(a, min, max);
		else if(min < max) {
			int half = (min+max)/2;
			mergeSort(a, min, half, cutoff);
			mergeSort(a, half+1, max, cutoff);
			merge(a, min, half, max);
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

	public static void main(String args[]) {
        long begin, end, i;
        int SIZE = 10, REPETITION = 22, CUTOFF = 10;
		int[] vet;
		HybridMergeSort hms;

		System.out.printf("HYBRID MERGE SORT (Size=%d, rept=%d)\n", SIZE, REPETITION);
		for (i = 0; i < REPETITION; i++) {
			vet = readNumbers("random_numbers.txt", SIZE);
			hms = new HybridMergeSort();

			begin = System.nanoTime();
			hms.mergeSort(vet, 0, vet.length-1, CUTOFF);
			end = System.nanoTime();
			System.out.println(TimeUnit.MILLISECONDS.convert(end - begin, TimeUnit.NANOSECONDS));
            /**
			for (int iii : vet) {
                System.out.println(iii);
            }
            **/
		}
	}
}
