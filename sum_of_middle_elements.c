/* 
	Sum of middle elements of two sorted array - GeeksForGeeks
	Problem Link: https://practice.geeksforgeeks.org/problems/sum-of-middle-elements-of-two-sorted-arrays/0/

	Author: Shyam Kumar

*/


#include <stdio.h>
#include <stdlib.h>

void merge( int *arr1, int *arr2, int *arr, int N ) {
    
    int i = 0, j = 0, k = 0;
    
    /* Comparing and storing until one of the two array is complete */
    while( i < N && j < N ) {
        
        if( arr1[i] < arr2[j] )
            arr[k++] = arr1[i++];
        else
            arr[k++] = arr2[j++];
    }
    
    // arr1 is complete
    if( i == N )
        while(j < N)
            arr[k++] = arr2[j++];
    else 	// arr2 is complete
        while(i < N)
            arr[k++] = arr1[i++];
            
}

int sum_of_middle_elements(int *arr1, int *arr2, int N) {
    
    int *arr;
    arr = (int*)malloc(sizeof(int)*(2*N));
    
    merge(arr1, arr2, arr, N);

    // Adding the N/2th element and (N/2+1)th element of the final array 
    int sum = arr[N-1] + arr[N];
    return sum;

}

void input_array(int *arr, int N) {
    
    int i;
    for(i=0; i < N; i++) 
        scanf("%d",&arr[i]);
}

int main() {
	int t, N, ans;
	scanf("%d",&t);
	
	while(t > 0) {
	    
	    scanf("%d",&N);
	    int arr1[N], arr2[N];
	    input_array(arr1, N);
	    input_array(arr2, N);
	    ans = sum_of_middle_elements(arr1,arr2, N);
	    printf("%d\n",ans);
	    t--;
	}
	return 0;
}