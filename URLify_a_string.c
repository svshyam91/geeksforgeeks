#include <stdio.h>
#include <string.h>

void URLify_a_string( char *str ) {

	int l, fl, sp = 0, flag = 0, j, i, last_index;

	l = strlen(str);
	// Finding the number of spaces && index of last alphabet

	for( i = 0; i < l-1; i++ ) {

		/* last index */
		if( (str[i] >= 97 && str[i] <= 123) || (str[i] >= 65 && str[i] <= 91) )
			last_index = i;

		/* Number of spaces in between */
		if( str[i] == ' ' && ( (str[i+1] >= 97 && str[i+1] <= 123)
		 || (str[i+1] >= 65 && str[i+1] <= 91) ))
			sp++;
	}

	/* Required length to store final string */
	fl = l + (sp * 2);

	/* Storing the last character to be null */
	str[fl-1] = '\0';

	j = fl-2;
	for( i = last_index; i >= 0; i-- ) {

		/* If the character is not space then store it at the end of final string */
		if( str[i] != ' ' )
			str[j] = str[i];

		/* If the character is space then store %20 in place of space */
		else {
			str[j] = '0';
			str[j-1] = '2';
			str[j-2] = '%';
			j = j-2;
		}
		j--;
	}
	return;
}

int main(int argc, char const *argv[])
{
	char str[100];
	int len, t;

	printf("\nEnter the number of test cases: ");
	scanf("%d",&t);

	while(t--) {
		// Input the string
		printf("Enter the string:");

		// This scanf clears the input buffer
		scanf("\n");

		fgets(str, sizeof(str), stdin);

		// Input the number of characters in the string 
		printf("\nEnter the length of the string: ");
		scanf("%d",&len);

		URLify_a_string( str );

		puts(str);
	}
	return 0;
}