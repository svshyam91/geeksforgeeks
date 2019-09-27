#include <iostream>
using namespace std;

int main() {

    int n, r, c, i, j, x1, x2, y1, y2;
    
	cin>>n;
	while(n>0) {
	    cin>>r>>c;
	    
	    int **arr=new int*[r];
	    for(i=0; i < r; i++)
	        arr[i] = new int[c];
	        
	    for(i=0; i<r; i++) {
	        for(j=0; j<c; j++) {
	            cin>>arr[i][j];
	        }
	    }
	    
	    /*// Printing the matrix
	    for(i=0; i < r; i++) {
	    	for(j=0; j < c; j++) {
	    		cout<<"\narr["<<i<<"]["<<j<<"]: "<<arr[i][j];
	    	}
	    }*/
	    
	    
	    cin>>x1>>y1>>x2>>y2;
	    
	    int sum=0;
	    x1--;
	    x2--;
	    y1--;
	    y2--;
	    for(i=x1; i<=x2; i++) {
	        for(j=y1; j<=y2; j++) {
	            // cout<<"\narr[i][j]: "<<arr[i][j];
	            sum+=arr[i][j];
	        }
	    }
	    cout<<sum;
	    n--;
	}
	return 0;
}