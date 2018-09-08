/* 	
	Path To Reach Origin Problem on GeeksForGeeks 
	Problem Link: https://practice.geeksforgeeks.org/problems/paths-to-reach-origin/0
	
	Note: This solution is based on Dynamic Programming (Memoization)

	Author: Shyam Kumar

*/

#include <stdio.h>
#include <stdlib.h>
// #include <time.h>

// clock_t start, end;

unsigned long int **arr;

unsigned long int reachOrigin( int n, int m ) {

	if( arr[n][m] == -1 ) {
		/* If n = 0 (1st row) or m = 0 (1st column) then return 1
			becoz from any cell in 1st row or 1st column, there
			will be only 1 path to origin */
		if( n == 0 || m == 0 )
			return 1;

		arr[n][m] = reachOrigin( n, m-1 ) + reachOrigin( n-1, m );
	}

	/* Remember: This statement is outside IF and not enclosed 
		inside ELSE */
	return arr[n][m];
	
}

int main(int argc, char const *argv[])
{
	start = clock();
	int n, m, k, i, j;
	unsigned long int ans;

	printf("Enter the number of Test Cases:");
	scanf("%d",&t);

	while(t--) {

		printf("Enter the number of rows:");
		scanf("%d",&n);
		printf("\nEnter the number of columns:");
		scanf("%d",&m);

		/* The reason for incrementing n and m is that we have to 
			find the total number of paths from (n, m) to 
			(0, 0) and not (1, 1). Therefore, we have to
			increase 1 row and 1 column */
		n++;
		m++;

		/* Dynamic memory Allocation of 2D array*/
		arr = (unsigned long int**)malloc( n * sizeof( unsigned long int *) );
		for( k = 0; k < n; k++ ) 
			arr[k] = (unsigned long int*)malloc( m * sizeof( unsigned long int ) );

		/* Initializing the 2D array */ 
		for( i = 0; i < n; i++ ) {
			for( j = 0; j < m; j++ ) {
					arr[i][j] = -1;
			}
		}

		ans = reachOrigin( n-1, m-1 );
		printf("\n\nAns = %lu",ans);
	}

	// end = clock();
	// printf("\nTime = %f", ((double)end-start))/CLOCKS_PER_SEC;
	return 0;
}
