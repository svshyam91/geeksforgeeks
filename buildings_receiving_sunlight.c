/* 
	Building Receiving Sunlight - GeeksForGeeks
	Problem Link: https://practice.geeksforgeeks.org/problems/buildings-receiving-sunlight/0

	Author: Shyam Kumar
	Date: 10th Sep, 2019

*/

#include <stdio.h>

int buildings_receiving_sunlight( int *arr, int size ) {
    
    int max = arr[0], count = 0, i;
    
    for( i = 0; i < size; i++ )
        if( arr[i] >= max ) {
            max = arr[i];
            count++;
        }
      
    return count;      
}

int main() {
    
    int t, size, i;
    
	scanf("%d",&t);
	while( t > 0 ) {
	    
	    scanf("%d",&size);
	    int arr[size];
	    
	    for(i = 0; i < size; i++ ) 
	        scanf("%d",&arr[i]);
	    
	    int ans = buildings_receiving_sunlight( arr, size );
	    printf("%d\n",ans);
	    t--;
	}
	return 0;
}