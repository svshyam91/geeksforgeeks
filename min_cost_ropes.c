/*
	Minimum Cost of Ropes - GeeksForGeeks
	Problem Link: https://practice.geeksforgeeks.org/problems/smallest-number/0/

	Author: Shyam Kumar	

*/

// Incorrect

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

	// swap arr[i+1] and arr[r]
	temp = arr[i+1];
	arr[i+1] = arr[r];
	arr[r] = temp;
	return i+1;
}

void quicksort( int *arr, int p, int r ) {
	int q;

	if( p < r) {
		q = partition( arr, p, r );
		quicksort( arr, p, q-1 );
		quicksort( arr, q+1, r );
	}
}

int min_cost_ropes( int n, int *arr ) {
	quicksort( arr, 0, n-1 );

	int sum = 0, sum2 = 0, i;

	sum = arr[0] + arr[1];
	sum2 = sum;
	// printf("sum = %d",sum)
	for( i = 2; i < n; i++ ) {
		sum = sum + arr[i];
		sum2 = sum2 + sum;
	}
	return sum2;
}

int main(int argc, char const *argv[])
{
	int t, n, i, ans;

	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);

		int *arr = (int*)malloc( n * sizeof(int));
		for(i = 0; i < n; i++ )
			scanf("%d",&arr[i]);

		ans = min_cost_ropes( n, arr ); 
		printf("ans = %d\n",ans);
	}
	return 0;
}