/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".
INPUTS: Two strings.
OUTPUT: common words in two given strings, return 2D array of strings.
ERROR CASES: Return NULL for invalid inputs.
NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>

#define SIZE 31


int  pattern(char *str1, char *str2, int first, int last, int count1, char **result)
{
	int l = 0;
	char search[SIZE];
	int k = 0;
	int temp = last - first;
	int count2 = temp;

	while (temp != 0)
	{
		search[k] = str2[first];
		k++;
		first++;
		temp--;
	}
	search[k] = '\0';

	int flag, i, j;

	for (i = 0; i <= count1 - count2; i++)
	{
		for (j = i; j < i + count2; j++)
		{
			flag = 1;
			if (str1[j] != search[j - i])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			break;
	}

	if (flag == 1)
	{
		int m = 0;
		while (count2 != 0)
		{
			result[l][m] = search[m];
			m++;
			count2--;
		}

		result[l][m] = '\0';
		l++;
	}
	return flag;
}

char ** commonWords(char *str1, char *str2)
{
	if (str1 == '\0' || str2 == '\0')
		return NULL;
	int i, j;

	char **result = (char **)malloc(SIZE * sizeof(char *));

	for (i = 0; i<SIZE; i++)
		result[i] = (char *)malloc(SIZE * sizeof(char));

	i = 0, j = 0;
	int count1 = 0;
	int temp = 0;
	int flag = 0;

	while (str1[count1] != '\0')
	{
		if (str1[count1] == ' ')
			temp++;
		count1++;
	}

	if (temp == count1)
		return NULL;

	while (str2[i] != '\0')
	{
		if (str2[i] == ' ' || str2[i + 1] == '\0')
		{
			temp++;
			if (str2[i] == ' ' && str2[i - 1] != ' ')
			{
				int tmp = pattern(str1, str2, j, i, count1, result);
				if (tmp == 1)
					flag = 1;
			}
			if (str2[i + 1] == '\0')
			{
				int tmp = pattern(str1, str2, j, i + 1, count1, result);
				if (tmp == 1)
					flag = 1;
			}

			j = i + 1;
		}
		i++;
	}

	if (flag == 0)
		return NULL;
	else
		return result;
}