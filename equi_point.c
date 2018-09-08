/*
	Equilibrium Point - GeeksForGeeks
	Problem Link: https://practice.geeksforgeeks.org/problems/equilibrium-point/0

	Author: Shyam Kumar
	
*/

#include <stdio.h>
#include <stdlib.h>

int equi_point( int *arr, int n ) {
	int i, l_sum = 0, r_sum = 0, t_sum = 0;

	if( n == 1 )
		return 0;

	for( i = 0; i < n; i++ )
		t_sum += arr[i];

	i = 0; 
	while( i < n-2 ) {
		l_sum += arr[i];
		r_sum = t_sum - (l_sum + arr[i+1]);
		if( l_sum == r_sum )
			return i+1;
		i++;
	}
	return -2;
}

int main(void) {
	int q, n, result, i, j;

	scanf("%d",&q);
	for( i = 0; i < q; i++ ) {

		scanf("%d",&n);

		int *arr = (int*)malloc(sizeof(int) * n);

		// Input array
		for( j = 0; j < n; j++ ) 
			scanf("%d",&arr[j]);

		result = equi_point( arr, n );
		printf("%d\n",result+1);
	}
	return 0;
}
