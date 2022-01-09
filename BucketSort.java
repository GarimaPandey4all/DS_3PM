package com.brainmentors.dsa.sorting;

public class BucketSort {
	
	public static void bucketSort(int arr[], int n)
	{
		int i, j;
		
		int count[] = new int[n + 1];
		
		for(i = 0; i < n; i++)
		{
			(count[arr[i]])++;
		}
		
		for(i = 0, j = 0; i <= n; i++)
		{
			while(count[i] > 0) // 2 > 0, 1 > 0, 0 > 0
			{ 
				arr[j++] = i; // 1, 1
				count[i]--; // 2 - 1 = 1, 1 - 1 = 0
			}
		}
	}
	
	public static void printArray(int arr[])
	{
		System.out.println("\nBucket Sort is");
		for(int i = 0; i < arr.length; i++)
		{
			System.out.print(arr[i]+" ");
		}
		
		System.out.println();
	}
	
	public static void main(String[] args) {
	
		int arr[] = {5, 7, 8, 2, 4, 3, 1, 6, 5};
		
		bucketSort(arr, arr.length);
		
		printArray(arr);
	}
}