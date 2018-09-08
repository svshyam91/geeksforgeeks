/*
	Mininum Sum formed by Digits - GeeksForGeeks
	Problem Link: https://practice.geeksforgeeks.org/problems/min-sum-formed-by-digits/0

	Author: Shyam Kumar

*/

#include <stdio.h>
#include <stdlib.h>

int partition( int *arr, int p, int r ) {
	int x, i, j, temp;
	x = arr[r];
	i = p-1;
	for( j = p; j < r; j++ ) {
		if( arr[j] <= x ) {
			i++;
			// Swap arr[i] and arr[j]
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	// Swap arr[i+1] and arr[r]
	temp = arr[i+1];
	arr[i+1] = arr[r];
	arr[r] = temp;
	return i+1;
}

void quicksort( int *arr, int p, int r ) {
	int q;
	if( p < r ) {
		q = partition( arr, p, r );
		quicksort( arr, p, q-1 );
		quicksort( arr, q+1, r );
	}
	return;
}

int min_sum_digits( int n, int *arr ) {

	int num1 = 0, num2 = 0, i;

	quicksort( arr, 0, n-1 );
	for( i = 0; i < n; i++ ) {
		if( i % 2 == 0 )
			num1 = num1 * 10 + arr[i];
		else
			num2 = num2 * 10 + arr[i];
	}
	return num2+num1;
}

int main(int argc, char const *argv[])
{
	int t, n, i, ans;

	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		int *arr = (int*)malloc( n * sizeof(int));
		for( i = 0; i < n; i++ )
			scanf("%d",&arr[i]);
		ans = min_sum_digits( n, arr );
		printf("\nans = %d",ans);
	}
	return 0;
}
