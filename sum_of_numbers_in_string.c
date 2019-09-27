#include <stdio.h>
#include <string.h>

int sum_of_numbers_in_string( char* str ) {
    
    int l = strlen(str);
    int num = 0, sum = 0, i;
    
    for( i=0; i < l; i++ ) {
        
        // If the character is a digit
        if(str[i] >= 48 && str[i] <= 57) {
            
            // Converting the character to number and adding it to num
            num = num * 10 + (str[i] - 48);
        }
        else {
            // If the number is not number then add the previous num to sum
            
            sum += num;
            num = 0;
        }
    }
    if(str[l-1] >= 48 && str[l-1] <= 57)
        sum += num;
        
    return sum;
}

int main() {
	int t, ans;
	char* str;
    scanf("%d",&t);
	while(t>0) {
	    scanf("%s",str);
	    ans = sum_of_numbers_in_string(str);
	    printf("%d",ans);
	    t--;
	}
	return 0;
}