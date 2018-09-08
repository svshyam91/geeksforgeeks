/*
	Leaders in an array - GeeksForGeeks	
	Problem Link: https://practice.geeksforgeeks.org/problems/leaders-in-an-array/0

	Author: Shyam Kumar

*/


#include <stdio.h>
#include <stdlib.h>

 void leadersArray( int *arr, int n ) {
 	int i, j, k = 0;
 	int *ans = (int *)malloc( sizeof( int ) * n );
 	for( i = 0; i < n-1; i++ ) {
 		for( j = i+1; j < n; j++ ) {
 			if( arr[j] >= arr[i] ) 
 				break;
 		}
 		if( j == n ) 
 			ans[k++] = arr[i];
 	}
 	for( i = 0; i < k; i++ ) 
 		printf("%d ",ans[i]);
 	printf("%d\n", arr[n-1]);     //Printing the last element
 	return;
 }

int main( void ) {
	int t, n, i, j;

	scanf("%d",&t);
	for( i = 0; i < t; i++ ) {
		scanf("%d",&n);
		int *arr = (int *)malloc(sizeof( int ) * n);
		
		for( j = 0; j < n; j++ )
			scanf("%d",&arr[j]);
		leadersArray( arr, n );
	}
	return 0;
}
