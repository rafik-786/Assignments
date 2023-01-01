#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <time.h>
void printArray(const int *arr, int size) {
	printf("\n[-Array-]\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i] );
	}
	printf("\n");
}

int main()
{
	srand(time(0));
	int n;
	scanf("%d", &n);

	int *arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)scanf("%d", &arr[i]);

	int indx = rand() % n;
	int ele = arr[indx];
	printf("Element: %d\n", ele);
	// scanf("%d", &ele);

	//find the postion
	int lesser = 0, higher = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < ele) lesser++;
		else if (arr[i] > ele) higher++;
	}

	//create two array;
	int *arrLesser = (int*)malloc(sizeof(int) * lesser);
	int *arrHigher = (int*)malloc(sizeof(int) * higher);

	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < ele) arrLesser[k++] = arr[i];
	}

	k = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > ele) arrHigher[k++] = arr[i];
	}

	printArray(arrLesser, lesser);
	printArray(arrHigher, higher);
	return 0;
}