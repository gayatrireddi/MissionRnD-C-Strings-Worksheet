/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/
#include<string.h>
char removeSpaces(char *str) {
	int i = 0, j, k, l;
	if (str == '\0' || str == "")
		return '\0';
	l = strlen(str);
	while (str[i] != '\0'){
		if (str[i] != ' ')
			i++;
		else
		{
			j = k = i;
			while (str[j] == ' ')
				j++;
			for (; j < (l + 1); j++)
			{
				str[k] = str[j];
				k++;
			}
		}
	}
}




