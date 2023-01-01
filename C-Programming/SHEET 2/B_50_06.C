#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int compfunc(const void* a, const void* b)
{
	return (*(int*)a > * (int*)b);
}
void sortArray(int *arr, int size) {
	qsort(arr, size, sizeof(int), compfunc);
}

int main()
{
	int m = 3;
	int n = 3;
	scanf("%d %d", &m, &n);
	int len1 = (m * n);


	int *arr1 = (int*)malloc(sizeof(int) * len1);
	for (int i = 0; i < len1; i++)
		scanf("%d", &arr1[i]);


	sortArray(arr1, len1);

	int p = 2;
	int q = 2;
	scanf("%d %d", &p, &q);
	int len2 = (p * q);


	int *arr2 = (int*)malloc(sizeof(int) * len2);
	for (int i = 0; i < len2; i++)
		scanf("%d", &arr2[i]);

	sortArray(arr2, len2);


	int *res = (int*)malloc(sizeof(int) * (len1 + len2));
	int size = (len1 + len2);
	// merging
	int i = 0, j = 0, k = 0;
	while (i < len1 && j < len2) {
		if (arr1[i] < arr2[j]) {
			res[k] = arr1[i];
			k++;
			i++;
		}
		else {
			res[k] = arr2[j];
			k++;
			j++;
		}
	}

	while (i < len1) {
		res[k] = arr1[i];
		k++;
		i++;
	}
	while (j < len2) {
		res[k] = arr2[j];
		k++;
		j++;
	}

	// printArray(res, size);
	k = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < (2 * n); j++) {
			printf("%d ", res[k++]);
		}
		printf("\n");
	}

	return 0;
}