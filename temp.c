/*#include <stdio.h>
#include <stdlib.h>
int reachOrigin( int x, int y ) {
    static int count = 0;
    if( x >= 0 && y >= 0 ) {
        if( x == 0 && y == 0 ) {
            count++;
        }
        reachOrigin( x, y-1 );
        reachOrigin( x-1, y );
    }
    return count;
}

int main(void) {
    int x, y, path, t, i, prev = 0;
    scanf("%d",&t);
    for( i = 0; i < t; i++ ) {
        scanf("%d",&x);
        scanf("%d",&y);
        path = reachOrigin( x, y );
        printf("%d\n",( path - prev ) );
        prev = path;
    }
    return 0;
}
*/
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    char str[100];
    int l=pow(2,4);
    printf("%d",l);
    return 0;
}
