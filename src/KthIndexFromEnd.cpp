
/*
OVERVIEW: Given a string, return the letter at Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the letter at Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/

char KthIndexFromEnd(char *str, int K) {
	int n = 0;
	if (str == '\0' || str == "")
		return '\0';
	while (str[n] != '\0')
		n++;
	if (K < n || K>0)
		return str[n - K - 1];
}

