#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ll long long int
#define inputINT(num) scanf("%d",&num);
#define inputLONG(num)scanf("%ld",&num);
#define inputDOUBLE(num) scanf("%lf",&num);
#define printDOUBLE(num) printf("%lf ",num);
#define printINT(num) printf("%ld ",num);
#define print(STRING) printf(STRING);
#define printLine printf("\n");

int main()
{

	char *num = (char*)malloc(sizeof(char) * 100);
	scanf("%s", num);

	int n = 0;
	while (num[n++] != '\0');
	n--;

	//trim
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (num[i] == '0')
		{
			count++;
			break;
		}
	}

	num += count;
	n = n - count;

	printf("Trimmed Zeros': %s", num);
	printf("\nDigits: %d\n", n);

	//reverse
	char *rev = (char*)malloc(sizeof(char) * 100);

	for (int i = 0; i < n; i++) {
		rev[i] = num[i];
	}
	rev[n] = '\0';
	// printf("%s", rev);

	int l = 0;
	int r = n - 1;

	while (l < r) {
		char temp = rev[l];
		rev[l] = rev[r];
		rev[r] = temp;
		r--;
		l++;

	}

	printf("Reverse Number: %s\n", rev);

	//check
	int flag = 1;
	for (int i = 0; i < n; i++) {
		if (rev[i] != num[i]) {
			flag = 0;
			break;
		}
	}

	if (flag) printf("Palindrome\n");
	else printf("Not Palindrome\n");
	return 0;
}