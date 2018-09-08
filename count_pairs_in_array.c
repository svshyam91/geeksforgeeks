/* 
	Count Pairs in an Array - GeeksForGeeks
	Problem Link: https://practice.geeksforgeeks.org/problems/count-pairs-in-an-array/0

	Author: Shyam Kumar

*/

#include <stdio.h>
#include <stdlib.h>

int count_pairs_in_array( int n, int *arr ) {

	int i,j, count = 0;

	for( i = 0; i < n-1; i++ ) {
		for( j = i+1; j < n; j++ ) {
			if( i*arr[i] > j*arr[j])
				count++;
		}
	}

	return count;
}

int main(int argc, char const *argv[])
{
	int q,n, i, ans;

	scanf("%d",&q);
	while(q--) {

		scanf("%d",&n);
		int *arr = (int*)malloc( n * sizeof(int));

		for(i = 0; i < n; i++ )
			scanf("%d",&arr[i]);

		ans = count_pairs_in_array( n, arr );
		printf("\nans = %d",ans);
	}
	return 0;
}
