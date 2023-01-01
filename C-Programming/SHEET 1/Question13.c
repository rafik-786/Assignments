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

double mat[100][100];
double res[100][100];
double row[100][100];
void printMatrix(double mat[100][100], int r, int c) {
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++) {
			printDOUBLE(mat[i][j]);
		}
		printLine;
	}
	printLine;
}

void matrixMutlplication(int size) {
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			for (int k = 0; k < size; k++)
				res[i][j] += mat[i][k] * mat[k][j];
}


int main()
{
	int n;
	inputINT(n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			mat[i][j] = 0;

	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n - 1; j++) {
			mat[i][j] = rand() % 100;
			sum += mat[i][j];
		}
		mat[i][n - 1] = 1 - sum;

	}

	print("The matrix:\n");
	printMatrix(mat, n, n);


	print("The Coloumn Vector:\n");
	for (int i = 0; i < n; i++)
	{
		row[i][0] = (double)1 / n;
		printDOUBLE(row[i][0]);
		printLine;
	}

	// matrix exponentiation
	int p;
	inputINT(p);

	for (int i = 1; i < p; i++)
		matrixMutlplication(n);

	printLine;
	print("Matrix Exponentiation\n");
	printMatrix(res, n, n);

	double ans[100][2];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 1; j++) {
			for (int k = 0; k < n; k++) {
				ans[i][j] += res[i][k] * row[k][j];
			}
		}
	}



	print("The Coloumn Vector:\n");
	for (int i = 0; i < n; i++)
	{
		printDOUBLE(ans[i][0]);
		printLine;
	}



	return 0;
}

// 100 * 100 100 * 1