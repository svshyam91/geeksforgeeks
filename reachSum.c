#include <stdio.h>
#include <stdlib.h>

int arr[1000];

void initialize( int n ) {

	int i;
	for( i = 0; i <= n; i++ )
		arr[i] = -1;
	arr[0] = 1;
	arr[1] = 0;
	arr[2] = 0;
	return;
}

int reachSum( int n ) {
	if( arr[n] == -1 )
		arr[n] = reachSum( n - 3 ) + reachSum( n - 5 ) + reachSum( n - 10 );
	return arr[n];
}

int main(int argc, char const *argv[])
{
	int n, ans;
	scanf("%d",&n);
	initialize( n );

	ans = reachSum( n );
	printf("ans = %d",ans);
	return 0;
}