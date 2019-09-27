#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int substring_sum( char *str ) {
	int len, join = 0, i, j, k, num = 0, sum = 0;
	len = strlen( str );
	for( join = 0; join < len; join++ ) {
		for( i = 0; i < len-join; i++ ) {
			j = 0; k = i; num = 0;
			while( j <= join ) {
				num = num * 10;
				num = num + ( str[k] - 48 );
				j++;
				k++;
			}
			sum += num;
		}
	}
	return sum;
}

int main( void ) {
	int t, i, sum = 0;
	char str[100];
	printf("\nEnter the number of test cases:");
	scanf("%d",&t);
	for( i = 0; i < t; i++ ) {
		printf("\nEnter the string:");
		scanf("%s",str);
		sum = substring_sum( str );
		printf("\nThe sum of substrings of string is %d", sum );
	}
	return 0;
}