//DP: Minimum Operations

#include <stdio.h>
#include <stdlib.h>

int memo[100];

int min( int x, int y ) {
	int min = x;
	if( y < x )
		min = y;
	return min;
}

int min_oper( int n ) {

	int r;

	if( n == 0 )
		return 0;
	if( memo[n] != -1 )
		return memo[n];
	r = 1 + min_oper( n-1 );
	if( n % 2 == 0 )
		r = min( r, 1+min_oper( n/2 ) );
	memo[n] = r;
	return r;
}

int main( void ) {
	int t, n, i, j;
	printf("\nEnter the value of t:");
	scanf("%d",&t);
	for( i = 0; i < t; i++ ) {
		printf("\nEnter the value of n:");
		scanf("%d",&n);

		for( j = 0; j < 100; j++ )		//Initialization
			memo[j] = -1;

		int ans = min_oper( n );
		printf("\nThe minimum number of operations required are: %d\n", ans);
	}
	return 0;
}