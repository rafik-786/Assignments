#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

void printMat(int **arr, int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{
	int dim;
	scanf("%d", &dim);

	int **mat = (int**)malloc(sizeof(int*)*dim);
	for (int i = 0; i < dim; i++) {
		mat[i] = (int*)malloc(sizeof(int) * dim);
	}

	//input
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			scanf("%d", &mat[i][j]);


	printf("[Matrix]\n");
	printMat(mat, dim);

	//transpose  matrix
	int **tranpose = (int**)malloc(sizeof(int*)*dim);
	for (int i = 0; i < dim; i++) {
		tranpose[i] = (int*)malloc(sizeof(int) * dim);
	}

	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			tranpose[j][i] = mat[i][j];


	printf("[Transpose Matrix]\n");
	printMat(tranpose, dim);


	//resultant matrix
	int **res = (int**)malloc(sizeof(int*)*dim);
	for (int i = 0; i < dim; i++) {
		res[i] = (int*)malloc(sizeof(int) * dim);
	}

	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++) {
			res[i][j] = 0;
			for (int k = 0; k < dim; k++) {
				res[i][j] += mat[i][k] * tranpose[k][j];
			}
		}
	}

	printf("[A*A^T]\n");
	printMat(res, dim);


	//check orthogonal or not 

	int ortho = 1;

	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++) {
			if (i == j) {
				if (res[i][j] != 1) {
					ortho = 0;
					break;
				}
			} else {
				if (res[i][j] != 0) {
					ortho = 0;
					break;
				}
			}


		}
		if (!ortho) break;
	}

	printf("%s\n", ortho ? "[Orthogonal]" : "[NOT Orthogonal]");


	return 0;
}

/*

Input

3
1 0 0
0 -1 0
0 0 1

*/