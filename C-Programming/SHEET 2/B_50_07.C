#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
int strlen(char *s) {
	int size = 0;
	while (s[size] != '\0')
		size++;

	return size;
}

int strcmp(char *s1, char *s2) {

	int n = strlen(s1);
	int m = strlen(s2);

	for (int i = 0, j = 0; i < n && j < m; i++, j++) {
		if (s1[i] != s2[j]) return s1[i] < s2[j] ? -1 : 1;
	}
	return 0;
}
char* strrev(char *s) {
	int l = 0;
	int h = strlen(s) - 1;
	while (l < h) {
		char temp = s[l];
		s[l] = s[h];
		s[h] = temp;
		l++;
		h--;
	}
	return s;
}

char *strcat(char *s1, char *s2) {
	int n = strlen(s1);
	int m = strlen(s2);
	char* temp = (char*)malloc(sizeof(char) * (m + n + 1));
	for (int i = 0; i < n; i++)
		temp[i] = s1[i];

	for (int i = n; i < (m + n); i++)
		temp[i] = s2[i - n];
	temp[m + n] = '\0';
	return temp;

}
char *strcpy(char *dest, char *src) {
	if (dest == 0) return 0;

	int n = strlen(src);
	for (int i = 0; i < n; i++)
		dest[i] = src[i];

	dest[n] = '\0';

	return dest;
}


int main()
{

	while (1) {
		printf("[Menu]\n1.strlen()\n2.strcpy()\n3.strcat()\n4.strrev()\n5.strcmp()\n6.Exit\nEnter Choice:");
		int choice;
		scanf("%d", &choice);
		if (choice == 1) {
			// scanf("%s");
			printf("Enter The String: ");
			char str[100];
			scanf("%s", str);
			printf("Length: %d\n", strlen(str));
		} else if (choice == 2) {
			printf("Enter The String: ");
			char str[100];
			scanf("%s", str);
			char copy[100];
			strcpy(copy, str);
			printf("Copied String: %s\n", copy);
		} else if (choice == 3) {
			printf("Enter The String1: ");
			char str1[100];
			scanf("%s", str1);
			printf("Enter The String2: ");
			char str2[100];
			scanf("%s", str2);
			printf("Concated string: %s\n", strcat(str1, str2));
		} else if (choice == 4) {
			printf("Enter The String: ");
			char str[100];
			scanf("%s", str);
			strrev(str);
			printf("Reversed string: %s\n", str);
		} else if (choice == 5) {
			printf("Enter The String1: ");
			char str1[100];
			scanf("%s", str1);
			printf("Enter The String2: ");
			char str2[100];
			scanf("%s", str2);
			printf("Result: %d\n", strcmp(str1, str2));

		} else if (choice == 6) {
			break;
		} else {
			printf("\n[Wrong Choice]\n");
		}

		printf("\n");
	}
	return 0;
}