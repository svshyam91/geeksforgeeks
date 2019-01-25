/*
	Nearly Sorted Algorithm
	Problem Link: https://practice.geeksforgeeks.org/problems/nearly-sorted-algorithm/0

	Author: Shyam Kumar
*/
#include <stdio.h>
#include <stdlib.h>

void nearly_sorted_array( int *arr, int n, int k ) {
	int i, j, temp;
	for( i = 1; i < n; i++ ) {
		temp = arr[i];
		for( j = i-1; j >= i-k; j-- ) {
			if( arr[j] > temp ) {
				arr[j+1] = arr[j];
			}
			else
				break;
		}
		arr[j+1] = temp;
	}
}

int main(void) {

	int t, n, k, i;
	printf("Enter the number of test Cases: ");
	scanf("%d",&t);

	while(t--) {
		printf("Enter the value of n and k: ");
		scanf("%d %d", &n, &k);

		int *arr = (int*)malloc( n * sizeof(int) );

		printf("Enter the array: ");
		for( i = 0; i < n; i++ ) 
			scanf("%d",&arr[i]);

		nearly_sorted_array( arr, n, k );

		// Printing the array 
		for( i = 0; i < n; i++ ) {
			printf("%d ",arr[i]);
		}
	}
}
