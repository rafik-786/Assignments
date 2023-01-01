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
	int arr1[1000], arr2[1000];
	int size1;
	inputINT(size1);

	for (int i = 0; i < size1; i++)
		inputINT(arr1[i]);

	int size2;
	inputINT(size2);

	for (int i = 0; i < size2; i++)
		inputINT(arr2[i]);

	int res[1000];

	//merging ;

	int i = 0, j = 0, k = 0;

	while (i < size1 && j < size2) {
		if (arr1[i] < arr2[j]) {
			res[k] = arr1[i];
			k++;
			i++;
		}
		else {
			res[k] = arr2[j];
			j++;
			k++;
		}
	}

	while (i < size1) {
		res[k] = arr1[i];
		i++;
		k++;
	}
	while (j < size2) {
		res[k] = arr2[j];
		j++;
		k++;
	}


	int size = size1 + size2;

	for (int i = 0; i < size; i++)
		printINT(res[i]);

	return 0;
}