/*
    Karatsuba Algorithm - GeeksForGeeks
    Problem Link: https://practice.geeksforgeeks.org/problems/karatsuba-algorithm/0

    Author: Shyam Kumar
    Date: 16-09-2019

*/


#include <stdio.h>
#include <string.h>
#include <math.h>

int karatsuba_algo( char *str ) {
    int l, dec, powr, num1, num2, i; 

    l=strlen(str);
    i=l-1;

    /* Sometimes the last character as \n is also considered in string. 
        So, to remove that we have checked the condition and removed it when True. */
    if(str[i] == '\n')
        i=i-1;
    dec=0;
    powr=0;
    while(i>=0) {

        /* If the character is space, that means now we have to start again
            for the next binary number. This space is the space that seperates
            the two binary number */
        if(str[i] == ' ') {
            num1=dec;
            dec=0;
            powr=0;
        }
        else {
            dec+=(str[i]-48)*pow(2,powr);
            powr++;
        }
        i--;
    }
    num2=dec;
    return (num1*num2);
}

int main() {
    int t, ans;
    char str[100];
    scanf("%d ",&t);
    while(t>0) {
        fgets(str,100,stdin);
        ans=karatsuba_algo(str);
        printf("%d\n",ans);
        t--;
    }
    return 0;
}