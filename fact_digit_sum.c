/*
    Fact Digit Sum
    Problem Link: https://practice.geeksforgeeks.org/problems/fact-digit-sum/0

    Author: Shyam Kumar
    Date: 12-09-2019

*/


#include <stdio.h>

int fact( int num, unsigned long int *fact_arr ) {
    /* This function returns the factorial of num */
    
    if( fact_arr[num] != 0 )
        return fact_arr[num];
    else 
        return num*fact(num-1, fact_arr);
    
}

int fact_digit_sum( int x, int i ) {
    
    // printf("i = %d\n",i);
    unsigned long int fact_arr[10] = {0}, f;
    fact_arr[0] = fact_arr[1] = 1;

    unsigned long long int sum = 0;
    int num = i, rem;

    /* Finding the sum of factorial of digits */
    while(num != 0) {
        rem = num%10;
        f = fact(rem, fact_arr);
        fact_arr[rem] = f;
        sum += f;
        // printf("fact of %d=%u\n",rem,f);
        num = num/10;
    }
    
    /* If the found sum is equal to given number */
    if( sum == x )
        return i;
    return fact_digit_sum(x, i+1);
    
}

int main() {
    
    int t, ans;
    unsigned long long int x;

    scanf("%d",&t);
    while(t>0) {
        scanf("%llu",&x);
        ans = fact_digit_sum(x, 1);
        printf("%d\n",ans);
        t--;
    }
	return 0;
}