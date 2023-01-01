#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int compare(char *str1, char *str2)
{
	int n = 0;
	while (str1[n] != '\0') {
		n++;
	}
	int m = 0;
	while (str1[m] != '\0') {
		m++;
	}

	int i = 0, j = 0;

	while (i < n && j < m) {
		if (str1[i] == str2[j]) {
			i++;
			j++;
		}
		else {
			return str1[i] > str2[j];
		}
	}
	return 0;
}

void strcpy(char* dest, const char* src)
{
	char *ptr = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}
void swap(char *str1, char *str2) {
	char *temp = (char*)malloc(sizeof(char) * 20);
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);
}


int main()
{
	int n;
	scanf("%d", &n);

	char str[100][100];

	for (int i = 0; i < n; i++)
		scanf("%s", &str[i]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++)
		{
			if (compare(str[j], str[j + 1]))
			{
				swap(str[j], str[j + 1]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%s\n", str[i]);
	}


	return 0;
}
/*
Input

8
Spain
France
Germany
Argentina
Italy
Germany
Brazil
England

*/