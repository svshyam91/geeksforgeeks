// Incomplete

#include <stdio.h>
#include <stdlib.h>

// int *lookup;

int longest_subsequence1( int n, int *arr ) {

	int count[1000] = {0}, max = 1, i;

	for( i = 0; i < n; i++ ) {
		if( arr[i] == 0 )
			continue;
		count[arr[i]]++;
		//printf("\ni = %d\tarr[i] = %d\tcount[arr[i]] = %d\tcount[arr[i]+1] = %d", i, arr[i], count[arr[i]], count[arr[i]+1] );

		if( (count[arr[i]] + count[arr[i]-1]) > max ) {
			max = (count[arr[i]] + count[arr[i]-1]);
			if( max == 455)
				printf("arr[%d]= %d",i, arr[i]);
		}
		if( (count[arr[i]] + count[arr[i]+1]) > max ) {
			max = (count[arr[i]] + count[arr[i]+1]);
			if( max == 455)
				printf("arr[%d]= %d",i, arr[i]);
		}
	}
	return max;

}

int main(int argc, char const *argv[])
{
	int i, n, ans, t;

	printf("\nEnter the number of test cases:");
	scanf("%d",&t);

	while(t-- ) {

		printf("Enter the value of n:");
		scanf("%d",&n);

		int *arr = (int *)malloc( n * sizeof( int ));
		
		printf("\nEnter the array:");
		for( i = 0; i < n; i++ )
			scanf("%d",&arr[i]);

		ans = longest_subsequence1( n, arr );
		printf("\nAns = %d",ans);
	}
	return 0;

}