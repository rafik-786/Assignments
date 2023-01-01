#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

void swap(char *a, char *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void reverse(char *str, int l, int h) {
	if (l > h)return;
	swap(&str[l], &str[h]);

	reverse(str, l + 1, h - 1);
}

int main()
{

	char str[27];
	// scanf("%S", str);
	gets(str);

	int size = 0;
	while (str[size] != '\0') {
		size++;
	}
	char strCopy[27];
	for (int i = 0; i < 27; i++)
		strCopy[i] = str[i];

	int l = 0;
	int h = size - 1;
	while (l < h) {
		int temp = str[l];
		str[l] = str[h];
		str[h] = temp;
		l++;
		h--;
	}
	printf("Non Recursive: %s\n", str );

	reverse(strCopy, 0, size - 1);
	printf("Recursive: %s\n", strCopy );
	return 0;
}