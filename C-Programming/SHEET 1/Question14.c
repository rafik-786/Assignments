#include <stdio.h>
#include <stdio.h>
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

	int res[100][100] = {0};

	int size;
	inputINT(size);
	//initialize
	for (int i = 0; i < size; i++) {

		res[i][i] = 1;
		res[i][0] = 1;
	}

	//  fill boxes
	for (int i = 1; i < size; i++) {
		for (int j = 1; j < i; j++) {
			res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
		}
	}

	for (int i = 0; i < size; i++) {

		//print space
		for (int k = 0; k < size - i; k++) print(" ");
		for (int j = 0; j <= i; j++) printINT(res[i][j]);
		printLine;
	}




	return 0;

}