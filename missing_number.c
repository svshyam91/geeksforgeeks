/*
	Missing Number in an array - GeeksForGeeks
	Problem Link: https://practice.geeksforgeeks.org/problems/missing-number-in-array/0

	Author: Shyam Kumar

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findMissing( int n, int *arr, int *ans, int m ) {
	int i; 
	for(i = 0; i < n; i++) {
		ans[arr[i]-1] = 1;
	}
	for(i = 0; i < m; i++) {
		if(ans[i] == 0)
			return i+1;
	}
}

int main(void) {

	int t, n, result, i, j;
	scanf("%d",&t);

	for(i = 0; i < t; i++) {

		scanf("%d",&n);
		int *arr = (int*)malloc(sizeof(int)* n-1);
		int *ans = (int*)malloc(sizeof(int) * n);
		for(j = 0; j < n; j++) {
			ans[i] = 0;
		}
	
		for(j = 0; j < n-1; j++) {
			scanf("%d",&arr[j]);
		}
		result = findMissing(n-1, arr, ans, n);
		printf("%d\n",result);
	}
	return 0;
}
