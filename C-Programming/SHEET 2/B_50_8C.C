#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

void printArray(const int *arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i] );
	}
	printf("\n");
}
void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void generatePermutation(int *arr, int size, int keepfix)
{
	if (keepfix == size) {
		printArray(arr, size);
		return;
	}

	for (int i = keepfix; i < size; i++) {
		swap(&arr[keepfix], &arr[i]);
		generatePermutation(arr, size, keepfix + 1);
		swap(&arr[keepfix], &arr[i]);
	}

}


int main()
{
	int size = 3;
	scanf("%d", &size);
	int arr[100];
	for (int i = 0; i < size; i++)
		scanf("%d", &arr[i]);

	generatePermutation(arr, size , 0);


	return 0;
}