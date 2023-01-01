#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int main()
{

	FILE *fo = fopen("fInput.txt", "r");
	FILE *fw = fopen("foutput.txt", "w");

	if (fo == NULL || fw == NULL) {
		printf("Error!");
		return -1;
	}

	char ch;
	while ((ch = fgetc(fo)) != EOF) {

		if (ch >= 'a' && ch <= 'z' )
			ch = ch - (1 << 5) ;

		fprintf(fw, "%c", ch);
	}

	fclose(fo);
	fclose(fw);


	return 0;
}