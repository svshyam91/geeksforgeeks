#include <stdio.h>
#include <stdlib.h>

void sort_specific_order( int *arr, int n ) {

	int i, temp2, p, q, j;

	/* temp array is used to store the sorted array */
	int *temp = (int*)malloc( n * sizeof( int ) );

	/* Initializing the temp array */
	for( i = 0; i < n; i++ )
		temp[i] = 0;

	/* p and q store the smallest odd(p) and even(q) element index */
	p = -1;
	q = n;

	for( i = 0; i < n; i++ ) {

		// Odd
		if( arr[i] % 2 != 0 ) {
			j = p+1;

			/* Shifting the elements forward till smaller elements 
				are found */
			while( (temp[j-1] < arr[i]) && (j > 0) ) {
				temp[j] = temp[j-1];
				j--;
			}

			/* Storing the elements at right place */
			temp[j] = arr[i];
			p++;
		}

		// Even
		else {
			j = q-1;

			/* Shifting the elements backward till smaller elements
				are found */ 
			while( temp[j+1] < arr[i] && j < n-1 ) {
				temp[j] = temp[j+1];
				j++;
			}

			/* Storing the elements at right place */
			temp[j] = arr[i];
			q--;
		}
	}

	/* Printing the array */
	for( i = 0; i < n; i++ )
		printf("%d ",temp[i]);
}

int main(int argc, char const *argv[])
{
	int n, i, t;

	scanf("%d",&t);
	while(t--) {

		scanf("%d",&n);
		int *arr = (int*)malloc( n * sizeof( int ));

		for(i = 0; i < n; i++ )
			scanf("%d",&arr[i]);

		sort_specific_order( arr, n );
		printf("\n");
	}

	return 0;
}