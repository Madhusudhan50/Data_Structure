package com.bubalsort.org;

import java.util.Scanner;

public class BubbleSort {

	public static void main(String[] args) {

		int temp;

		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the size of Array");
		int size = sc.nextInt();

		int arr[] = new int[size];
		
		System.out.println("Enter The Values");

		for (int v = 0; v < arr.length; v++) {
			arr[v] = sc.nextInt();
		}

		System.out.println("Before Sorting");
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + "\t");
		}

		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr.length - 1 - i; j++) {

				if (arr[j] > arr[j + 1]) {
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}

		System.out.println("\nAfter Sorting");
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + "\t");
		}
		sc.close();
	}
}
