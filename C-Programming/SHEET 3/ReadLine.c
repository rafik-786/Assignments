#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int main()
{

#include <stdio.h>
#include <stdlib.h>
	int num;
	char c;
	FILE *fp, *fp2;

	fp = fopen("demo.txt", "r");
	if (fp == NULL) {
		printf("Error!");
		exit(1);
	} else {
		printf("sucess\n");
	}
	fclose(fp);

	return 0;
}