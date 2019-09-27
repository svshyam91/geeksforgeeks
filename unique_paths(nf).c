// DP: Number of Unique Paths

#include <stdio.h>
#include <stdlib.h>

int count = 0;

void minimumPoints( int r, int c, int x, int y ) {
	if( x < r && y < c ) {
		if( x == r-1 && y == c-1 ) {
			count++;
		}
		minimumPoints( r, c, x+1, y );
		minimumPoints( r, c, x, y+1 );
	}
}

int main( void ) {
	int r, c, t, i, j, k, z, a;
	printf("\nEnter the number of test cases:");
	scanf("%d",&t);
	for( i = 0; i < t; i++ ) {
		printf("\nEnter the number of rows:");
		scanf("%d",&r);
		printf("\nEnter the number of columns:");
		scanf("%d",&c);
		minimumPoints( r, c, 0, 0 );
		printf("\nThe value of count: %d", count);
	}
	return 0;
}