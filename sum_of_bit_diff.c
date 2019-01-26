/*
	Sum of Bit Difference
	Problem Link: https://practice.geeksforgeeks.org/problems/sum-of-bit-differences/0

	Author: Shyam Kumar
*/

#include <stdio.h>
#include <stdlib.h>

void find_binary( int num, int *bin ) {
	int j = 3;

	while( num ) {
		if( num % 2 == 0 )
			bin[j--] = 0;
		else
			bin[j--] = 1;
		num = num / 2;
	}
	for( j = 0; j < 4; j++ )
		printf("%d ",bin[j]);
	return;
}

int sum_of_bit_pairs( int x, int y ) {

	int x_bin[4] = {0}, y_bin[4] = {0}, sum = 0, i;

	find_binary( x, x_bin );
	find_binary( y, y_bin );
	for( i = 0; i < 4; i++ ) {
		if( x_bin[i] != y_bin[i] ) 
			sum++;
	}
	return sum;

}

int array_pairs( int *arr, int n ) {
	int i, j, sum = 0;
	for( i = 0; i < n-1; i++ ) {
		for( j = i+1; j < n; j++ ) {
			sum = sum + sum_of_bit_pairs(arr[i], arr[j]);
		}
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	int t, n, i, ans;
	printf("Enter the number of test cases: ");
	scanf("%d",&t);

	while(t--) {
		printf("Enter the size of the array: ");
		scanf("%d",&n);
		int *arr = (int*)malloc(n* sizeof(int));
		printf("Enter the array: ");
		for( i = 0; i < n; i++ ) 
			scanf("%d",&arr[i]);

		ans = array_pairs( arr, n );

		printf("\nSum = %d",ans);
	}
	return 0;
}
