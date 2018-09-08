/*
	Smallest Number - GeeksForGeeks
	Problem Link: https://practice.geeksforgeeks.org/problems/min-sum-formed-by-digits/0

	Author: Shyam Kumar

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int smallest_number( int s, int d ) {
	int sm, i, lg_s;

	/* Smallest d digit number */
	sm = pow(10,d-1);

	/* Largest sum of d digits*/
	lg_s = 9 * d;

	/* s is greater than largest sum */
	if( s > lg_s )
		return -1;

	/* Decreasing 1 from total sum required */
	s--;
	for( i = 0; i < d; i++ ) {
		if( s >= 9) {
			sm = sm + 9 * pow(10,i);
			s = s-9;
		}
		else {
			sm = sm + s * pow(10,i);
			break;
		}
	}
	return sm;
}

int main(int argc, char const *argv[])
{
	int t, s, d, ans;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d",&s, &d);
		ans = smallest_number( s, d );
		printf("%d\n",ans);
	}
	return 0;
}
