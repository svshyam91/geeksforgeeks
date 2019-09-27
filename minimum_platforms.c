//Array -- Minimum Platforms

#include <stdio.h>
#include <stdlib.h>

int minPlatform( int *arv, int *dep, int n ) {

	int i, j, count, max_count, flag, k;
	int *stand = (int*)malloc( sizeof(int) * n );

	for( i = 0; i < n; i++ )
		stand[i] = 0;

	k = -1; count = 0; max_count = 0;
	for( i = 0; i < n; i++ ) {
		flag = 0;
		j = 0;
		while( j <= k ) {
			stand[j] = stand[j] - ( arv[i] - arv[i-1] );
			if( stand[j] > 0 ) {
				count++; 
				flag = 1;
			}
			j++;
		}
		if( count > max_count )
			max_count = count;
		if( flag == 0 )
			k = -1;
		stand[++k] = dep[i] - arv[i];
	}
	printf("\nmax_count = %d",max_count);
	return max_count;
}

int main( void ) {
	int t, n, j, i, minPlt;
	printf("\nEnter the number of test cases:");
	scanf("%d",&t);
	for( i = 0; i < t; i++ ) {
		printf("\nEnter the number of time intervals:");
		scanf("%d",&n);

		int *arv = (int*)malloc( sizeof(int) * n );
		int *dep = (int*)malloc( sizeof(int) * n );

		printf("\nEnter the arrival time:");
		for( j = 0; j < n; j++ )
			scanf("%d",&arv[j]);
		printf("\nEnter the departure time:");
		for( j = 0; j < n; j++ )
			scanf("%d",&dep[j]);

		minPlt = minPlatform( arv, dep, n );
		printf("\nThe minimum platforms required is %d", minPlt);
	}
	return 0;
}