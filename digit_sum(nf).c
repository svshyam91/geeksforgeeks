// Problem Not Found

#include <stdio.h>

char* digit_sum(int n)
{
    int l, f, sum = 0;
    l = n % 10;
    while(n) {
        sum += n % 10;
        if( n/10 != 0 )
            n = n / 10;
        else {
            f = n;
            n = n / 10;
        }
    }
    int rem = sum - (f+l);
    if( rem == (f+l) )
        return "YES";
    else
        return "NO";
    
    
}

int main(int argc, char const *argv[])
{
	int n, t, i;
	scanf("%d",&t);
	for( i = 0; i < t; i++ ) {
		scanf("%d",&n);
		char *ans = digit_sum(n);
		printf("%s",ans);
	}
	return 0;
}