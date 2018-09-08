/* 
	Count No of Hops - GeeksForGeeks
	Problem Link: https://practice.geeksforgeeks.org/problems/count-number-of-hops/0

	Note: This solution is based on Dynamic Programming( Memoization )

	Author: Shyam Kumar

*/

#include <stdio.h>
#include <stdlib.h>

int *lookup;

int no_of_hops( int n ) {
	if( lookup[n] == -1 ) {
		lookup[n] = no_of_hops(n-1) + no_of_hops(n-2) + no_of_hops(n-3);
	}
	return lookup[n];
}

void initialize( int n ) {
	int i;
	for( i = 0; i < n; i++ )
		lookup[i] = -1;

	/* Storing the number of ways to reach 1,2,3 */
	lookup[1] = 1;
	lookup[2] = 2;
	lookup[3] = 4;

	return;
}

int main(int argc, char const *argv[])
{
	int n, ans, t;

	printf("Enter the number of test cases:");
	scanf("%d",&t);

	while(t--) {

		printf("\nEnter the number of steps it has to hop:");
		scanf("%d",&n);

		/* Dynamically allocating of the lookup array 
			We will start storing values from index 1, 
			that's why size is 1 more.*/
		lookup = (int*)malloc(n+1 * sizeof(int ));

		/* Initializing the lookup array */
		initialize( n+1 );

		ans = no_of_hops(n);
		printf("\nThe number of hops required: %d", ans);

	}

	return 0;
}
