/* 	
	Path To Reach Origin Problem on GeeksForGeeks 
	Problem Link: https://practice.geeksforgeeks.org/problems/paths-to-reach-origin/0
	
	Note: This solution is not based on Dynamic Programming
			It is based on recursion.

	Author: Shyam Kumar

*/

#include <stdio.h>
#include <stdlib.h>
// #include <time.h>

// clock_t start, end;

int reachOrigin( int x, int y ) {
	static int count = 0;

	if( x >= 0 && y >= 0 ) {

		/* If reached at origin then increase the counter */
		if( x == 0 && y == 0 ) {
			count++;
		}

		/* Move Left */
		reachOrigin( x, y-1 );
		/* Move Up */
		reachOrigin( x-1, y );
	}
	
	return count;
}

int main(void) {
	// start = clock();
	int x, y, path, t, i;
	printf("\nEnter the number of test cases:");
	scanf("%d",&t);
	for( i = 0; i < t; i++ ) {
		printf("\nEnter the value of x:");
		scanf("%d",&x);
		printf("\nEnter the value of y:");
		scanf("%d",&y);
		path = reachOrigin( x, y );
		printf("\nThe number of ways to reach origin: %d", path );
	}
	// end = clock();
	// printf("Time = %f", ((double)end-start))/CLOCKS_PER_SEC;
	return 0;
}
