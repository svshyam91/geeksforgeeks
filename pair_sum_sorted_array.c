#include<stdio.h>
#include<stdlib.h>

void pair_sum_sorted_array( int*, int, int );

int main()
{
	int i, t, *arr, ans, k, n, count;
	scanf("%d",&t);
	while( t-- ) {
	    count = 0;
	    
	    scanf("%d",&n);
	    arr = (int*)malloc( n * sizeof(int ) );
	    for( i = 0; i < n; i++ ) 
	        scanf("%d",&arr[i]);
	    scanf("%d",&k);
	    
	    pair_sum_sorted_array( arr, n, k );
	}
	return 0;
}

void pair_sum_sorted_array( int *arr, int n, int k ) {
	int i, j, sum, count = 0;

	for( i = 0, j = n-1; i < j; ) {

		sum = arr[i] + arr[j];
		if( sum < k ) 
			i++;
		else if( sum > k )
			j--;
		else if( sum == k ) {
			printf("\n%d %d %d", arr[i], arr[j], k);
			count++;
			i++;
			j--;
		}
	}
	if( count == 0 )
		printf("\n-1");
	return;
}