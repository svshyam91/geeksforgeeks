#include <stdio.h>
#include <stdlib.h>

void pattern_s1(int);

int main( void ) {
	int n;
	scanf("%d",&n);
	pattern_s1(n);
	return 0;
}

void pattern_s1( int n ) {
	int i, j, temp;
	for( i = n; i > 0; i-- ) {
		temp = n;

		for( j = 0; j < n*i; j++ ) {
			if( j % i == 0 && j != 0 )
				temp--;
			printf("%d ",temp);
		}
		printf("\n");
	}
	return;
}