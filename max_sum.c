/* 
	Maximum Sum Problem on GeeksForGeeks
	Problem Link: https://practice.geeksforgeeks.org/problems/maximum-sum-problem/0

	Note: This solution is based on Dynamic Programming (Memoization)

	Author: Shyam Kumar

	
*/

#include <stdio.h>
#include <stdlib.h>

// typedef int unsigned long int;

unsigned long int *lookup;

unsigned long int max( unsigned long int a, unsigned long int b ) {
	if( b > a )
		return b;
	return a;
}

unsigned long int maximum_sum( unsigned long int n ) {
	if( lookup[n] == -1 ) {

		if( n < 4 )
			lookup[n] = n;
		else {
			lookup[n] = max( n, ( max(n/2, maximum_sum(n/2)) + 
						max(n/3, maximum_sum(n/3)) + max(n/4, maximum_sum(n/4)) ) );
		}
	}
	return lookup[n];
}

void initialize( unsigned long int n ) {
	unsigned long int i;

	for( i = 0; i < n; i++ ) 
		lookup[i] = -1;

	return;
}

int main(int argc, char const *argv[])
{
	int t;
	unsigned long int n, ans;

	printf("Enter the number of test cases:");
	scanf("%d",&t);

	while(t--) {
		printf("\nEnter the value of n:");
		scanf("%lu",&n);

		printf("\nn= %lu", n);

		/* Dynamically allocating the lookup array */
		lookup = (unsigned long int*)malloc( 100000 * sizeof( unsigned long int ) );

		/* Initializing the lookup array */
		initialize( n+1 );

		ans = maximum_sum( n );
		printf("\nAns = %lu", ans);
		//free(lookup);
	}
	return 0;
}
