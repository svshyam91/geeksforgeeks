/* 
	Pairs with Specific Difference Problem on GeeksForGeeks
	Problem Link: https://practice.geeksforgeeks.org/problems/pairs-with-specific-difference/0

	Note: This solution is NOT based on Dynamic Programming

	Author: Shyam Kumar


*/

#include <stdio.h>
#include <stdlib.h>

int partition(int arr[], int p, int r) {
	int i,j,x,temp;
	i = p-1;
	x = arr[r];
	for(j = p; j <= r-1; j++) {
		if(arr[j] <= x) {
			i = i+1;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	temp = arr[i+1];
	arr[i+1] = arr[r];
	arr[r] = temp;
	return i+1;
}

void quicksort(int arr[], int p, int r) {
	int q;
	if(p<r) {
		q = partition(arr,p,r);
		quicksort(arr,p,q-1);
		quicksort(arr,q+1,r);
	}
}


int pairs_specific_diff( int n, int *arr, int k ) {

	int i, j, sum = 0;

	quicksort( arr, 0, n-1 );

	for( i = n-1; i >= 1; i-- ) {
		if( arr[i] - arr[i-1] < k ) {
			sum = sum + (arr[i] + arr[i-1]);
			i--;
		}
	}
	return sum;
}

int main(int argc, char const *argv[])
{

	int i, n, k, ans, t;

	printf("\nEnter the number of test casees:");
	scanf("%d",&t);

	while(t--) {

		printf("Enter the value of N:");
		scanf("%d",&n);

		int *arr = (int*)malloc( 10000 * sizeof( int ) );
		printf("\nEnter the array :");
		for( i = 0; i < n; i++ ) 
			scanf("%d",&arr[i]);

		printf("\nEnter the value of k:");
		scanf("%d",&k); 

		ans = pairs_specific_diff( n, arr, k );
		printf("\nAns = %d", ans);

	}
	return 0;
}
