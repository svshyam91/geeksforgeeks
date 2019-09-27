/* 
	Reverse Coding - GeeksForGeeks
	Problem Link: https://practice.geeksforgeeks.org/problems/reverse-coding/0

	Author: Shyam Kumar

*/

#include <stdio.h>
#include <stdlib.h>

int reverse_coding(int n) {
	if(n==0)
		return 0;
	else
		return n+reverse_coding(n-1);
}

int main(int argc, char const *argv[])
{
	int t, n, m, ans;
	scanf("%d",&t);
	while(t>0){
		scanf("%d %d",&n,&m);
		ans = reverse_coding(n);
		if(ans==m)
			printf("1");
		else
			printf("0");
		t--;
	}
	return 0;
}