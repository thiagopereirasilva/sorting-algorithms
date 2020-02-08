package algoritmos;

import java.io.File;
import java.io.FileNotFoundException;
import java.lang.reflect.Array;
import java.util.Scanner;
import java.util.Vector;
import java.util.concurrent.TimeUnit;

public class MergeSort {

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

	public void mergeSort(int[] a, int min, int max){
		int half;
		if(min < max){
			half = (min+max)/2;
			mergeSort(a, min, half);
			mergeSort(a, half+1, max);
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

	public static void main(String args[]) {
        long begin, end, i;
        int SIZE = 10000, REPETITION = 20;
		int[] vet;
		MergeSort ms;

		System.out.printf("MERGE SORT (Size=%d, rept=%d) ORDER\n", SIZE, REPETITION);
		for (i = 0; i < REPETITION; i++) {
			//vet = readNumbers("random_numbers.txt", SIZE);
			vet = reverseOrder(SIZE);
			ms = new MergeSort();

			begin = System.nanoTime();
			ms.mergeSort(vet, 0, vet.length-1);
			end = System.nanoTime();

			System.out.println(TimeUnit.MILLISECONDS.convert(end - begin, TimeUnit.NANOSECONDS));
		}
	}
}
