#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

void printArray(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i] );
	}
	printf("\n");
}

int main()
{


	int n;
	scanf("%d", &n);

	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

	// int ith;
	// scanf("%d", &ith);
	int max3 = 3;
	int min5 = 5;
	int mid1 = arr[n >> 1];
	int mid2 = arr[(n >> 1) - 1];
	if (!(n & 1)) printf("Middle: %d %d\n", mid1, mid2);
	else printf("Middle: %d \n", mid1);


	int ans = INT_MAX;
	int curMax;
	while (max3--) {
		curMax = INT_MIN;
		for (int i = 0; i < n; i++) {
			if (arr[i] >= curMax && arr[i] < ans) {
				curMax = arr[i];
			}
		}
		ans = curMax;

	}
	printf("Third max: %d\n", ans);

	ans = INT_MIN;
	int curMin = arr[0];
	while (min5--) {
		curMin = INT_MAX;
		for (int i = 0; i < n; i++) {
			if (arr[i] <= curMax && arr[i] > ans) {
				curMin = arr[i];
			}
		}
		ans = curMin;

	}
	printf("Fifth min: % d\n", ans);

	return 0;
}

/*
input: 

8
7 6 5 4 3 2 1 8

7
7 6 5 4 3 2 1
*/