package algoritmos;

import java.io.File;
import java.io.FileNotFoundException;
import java.lang.reflect.Array;
import java.util.Scanner;
import java.util.Vector;
import java.util.concurrent.TimeUnit;
import java.util.Random;

public class RandomQuickSort {

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

	public void quickSort(int[] A, int p, int r){
		if(p<r){
			int q = randomized_partition(A, p, r);
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
		int SIZE = 10000, REPETITION = 20;
		int[] vet;
		RandomQuickSort qs;

		System.out.printf("RANDOM QUICK SORT (Size=%d, rept=%d)\n", SIZE, REPETITION);
		for (i = 0; i < REPETITION; i++) {
			//vet = readNumbers("random_numbers.txt", SIZE);
			vet = reverseOrder(SIZE);
			qs = new RandomQuickSort();

			begin = System.nanoTime();
			qs.quickSort(vet, 0, vet.length-1);
			end = System.nanoTime();

			System.out.println(TimeUnit.MILLISECONDS.convert(end - begin, TimeUnit.NANOSECONDS));
		}
	}
}
