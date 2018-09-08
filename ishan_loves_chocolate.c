/*
	Ishan Loves Chocolate Problem - GeeksForGeeks
	Problem Link:- https://practice.geeksforgeeks.org/problems/ishaan-loves-chocolates/0

	Author: Shyam Kumar

*/


#include <stdio.h>
#include <stdlib.h>

int ishan_loves_chocolate( int *arr, int n ) {
	int i,j;
	i = 0, j = n-1;
	while( i != j ) {
		if( arr[i] >= arr[j]  && i < j )
			i++;
		else if( arr[j] >= arr[i] && j > i )
			j--;
	}
	return arr[i];
}

int main(int argc, char const *argv[])
{
	int t, n, i, ans;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		int *arr = (int*)malloc( n * sizeof(int));
		for( i= 0; i < n; i++ )
			scanf("%d",&arr[i]);
		ans = ishan_loves_chocolate( arr, n );
		printf("ans = %d\n",ans);
	}
	return 0;
}
