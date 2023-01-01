 #include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int main()
{

	FILE *fo = fopen("fInput.txt", "r");
	FILE *fw = fopen("foutput.txt", "w");


	char ch = '.';
	int row = 0;
	int col = 0, t = 0, sum = 0;

	int **mat = malloc(sizeof(int*) * 100);
	int *colArray = malloc(sizeof(int) * 100);


	while ((ch = fgetc(fo)) != EOF) {
		if (ch != ' ' && ch != '\n') {
			colArray[t] = ch - 48; 
			t++; 
		}

		if (ch == '\n') {
			mat[row] = malloc(sizeof(int) * t); 

			for (int k = 0; k < t; k++)
				mat[row][k] = colArray[k];

			
			row++;
			col = t;
			t = 0;

		}

	}
	if (t != 0) {
		mat[row] = malloc(sizeof(int) * t);
		for (int k = 0; k < t; k++)
			mat[row][k] = colArray[k];
		row++;
	}

	for (int i = 0; i < row; i++) {
		int sum = 0;
		for (int j = 0; j < col; j++) {
			sum += mat[i][j];
		}
		fprintf(fw, "Row[%d]: %d\n", i, sum);
	}


	fprintf(fw, "Dimension: %dx%d\n", row, col);

	return 0;
}


/*

0 0 0 1 1 1 1 1
1 0 0 1 0 0 0 0
1 0 0 1 1 1 0 1
0 1 1 0 0 1 1 0


*/