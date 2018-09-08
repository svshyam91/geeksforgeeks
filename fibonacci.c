/* 
	Fibonacci Problem
	Note: This solution is based on Dynamic Programming (Memoization)

	Author: Shyam Kumar 

*/
#include <stdio.h>
#include <stdlib.h>

int *look;

int fib( int n ) {
	if( look[n] == -1 ) {
		if( n <= 1 ) 
			look[n] = n;
		else {
			look[n] = fib(n-1) + fib(n-2);
		}
	}
	return look[n];
}

int main(int argc, char const *argv[])
{
	int i, n, ans;

	printf("Enter the value of n:");
	scanf("%d",&n);

	/* Dynamic allocation of lookup array */
	look = (int*)malloc(n * sizeof(int ));

	/* Initializing the lookup array */
	for( i = 0; i < n; i++ )
		look[i] = -1;

	ans = fib(n-1);
	printf("ans = %d", ans);
	return 0;
}
