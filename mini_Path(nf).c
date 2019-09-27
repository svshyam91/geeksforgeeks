#include <stdio.h>
#include <stdlib.h>

int ans[100] = {0};

void store( int points ) {
	static int i = 0;
	ans[i++] = points;
	return;
}

void minimumPoints( int **arr, int r, int c, int x, int y, int points ) {
	if( x < r && y < c ) {
		points += arr[x][y];
		printf("\nx = %d y = %d points = %d", x, y, points);
		if( x == r-1 && y == c-1 ) {
			store( abs(points) );
			printf("\nPoints = %d",points);
		}
		minimumPoints( arr, r, c, x+1, y, points );
		minimumPoints( arr, r, c, x, y+1, points );
	}
}

int main( void ) {
	int r, c, t, i, j, k, z, a;
	int **arr;
	printf("\nEnter the number of test cases:");
	scanf("%d",&t);
	for( i = 0; i < t; i++ ) {
		printf("\nEnter the number of rows:");
		scanf("%d",&r);
		printf("\nEnter the number of columns:");
		scanf("%d",&c);
		arr = malloc( sizeof(int*) * r );
		for( z = 0; z < r; z++ ) {
			arr[z] = malloc( sizeof(int) * c );
		}
		printf("\nEnter the array:");
		for( j = 0; j < r; j++ ) {
			for( k = 0; k < c; k++ ) {
				scanf("%d",&arr[j][k]);
			}
		}
		minimumPoints( arr, r, c, 0, 0, 0 );
		int min = ans[0];
		printf("\nPrinting the array ans:");
		for( a = 1; ans[a] != 0; a++ ) 
			if( ans[a] < min )
				min = ans[a];
		printf("\nThe value of min: %d", min);
		printf("\nThe maximum points required %d", min+1);

	}
	return 0;
}