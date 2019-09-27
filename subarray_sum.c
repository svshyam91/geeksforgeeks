//Geeks For Geeks - Subarray with given sum

//Correct on this machine but not on GFG's machine

#include <stdio.h>
#include <stdlib.h>

void subarray_sum( int *arr, int n, int *start, int *end, int r_sum ) {

	int i, j, sum = 0;

	for( i = 0; i < n-1; i++ ) {
		sum = 0; 
		j = i;
		while( sum <= r_sum && j <= n ) {
			if( sum == r_sum ) {
				*start = i+1;
				*end = j;
				return;
			}
			sum += arr[j++];
		}
	}
	return;
}

int main(void) {
	int t, n, r_sum, start = 0, end = 0, i, j;
	printf("\nEnter the number of test cases:");
	scanf("%d",&t);
	for(i = 0; i < t; i++) {
		printf("\nEnter the value of n:");
		scanf("%d",&n);
		printf("\nEnter the required sum:");
		scanf("%d",&r_sum);

		int *arr = (int*)malloc(sizeof(int) * n);

		printf("\nEnter the array:");
		for(j = 0; j < n; j++) 
			scanf("%d",&arr[j]);
		subarray_sum( arr, n, &start, &end, r_sum );
		if( start == 0 && end == 0)
			printf("\nAnswer: -1");
		else {
			printf("\nAnswer: start = %d   end = %d", start, end);
		}
	}
	return 0;
}