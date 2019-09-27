//DP: Minimum Steps to One

#include <stdio.h>
#include <stdlib.h>

int memo[100];

int min( int x, int y ) {
	int min = x;
	if( y < x )
		min = y;
	return min;
}

int getMinSteps( int n ) {
	int r;

	if( n == 1 ) 
		return 0;
	if( memo[n] != -1 )
		return memo[n];
	printf("\nBefore -1: n = %d r = %d", n, r );
	r = 1 + getMinSteps( n-1 );
	printf("\nAfter -1: n = %d r = %d", n, r );
	if( n % 2 == 0 )
		r = min( r, 1 + getMinSteps( n/2 ) );
	printf("\nAfter /2: n = %d r = %d", n, r );
	if( n % 3 == 0 )
		r = min( r, 1 + getMinSteps( n/3 ) );
	printf("\nAfter /3: n = %d r = %d", n, r );
	printf("\nmemo[%d] = %d", n, r );
	memo[n] = r;
	return r;
}

int main( void ) {
	int n, i;
	printf("\nEnter the value of n:");
	scanf("%d",&n);
	for( i = 0; i < 100; i++ ) 
		memo[i] = -1;
	int ans = getMinSteps( n );
	printf("\nThe minimum number of steps required: %d\n", ans);
	return 0;
}