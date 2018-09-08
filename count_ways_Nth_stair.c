/* 
	Count ways to Nth stair - GeeksForGeeks
	Problem Link: https://practice.geeksforgeeks.org/
						problems/count-ways-to-nth-stairorder-does-not-matter/0/

	Note: This solution is based on Dynamic Programming( Memoization )

	Author: Shyam Kumar

*/

#include <stdio.h>
#include <stdlib.h>

int *lookup;

int nth_stair( int n ) {
	if( lookup[n] == -1 ) {

		/* When n is multiple of 2 then no. of ways from 
			n-1 is increased by 1 because no. of 2's in the 
			combination is increased */
		if( n%2 == 0 )
			lookup[n] = 1;
		else
			lookup[n] = 0;

		/* Adding the no. of ways of n-1 */
		lookup[n] = lookup[n] + nth_stair( n-1 );

	}
	return lookup[n];
}

void initialize( int n ) {
	int i;
	for( i = 0; i < n; i++ ) 
		lookup[i] = -1;

	lookup[1] = 1;
	lookup[2] = 2;

	return;
}

int main(int argc, char const *argv[])
{
	int n, ans, t;

	printf("Enter the number of test cases:");
	scanf("%d",&t);

	while(t--) {

		printf("Enter the Nth Stair:");
		scanf("%d",&n);

		/* Dynamically allocating memory for lookup table */
		lookup = (int*)malloc( n+1 * sizeof(int ));
		
		/* Initializing the lookup table */
		initialize( n+1 );

		ans = nth_stair( n );
		printf("\nAns = %d",ans);

	}
	return 0;
}
