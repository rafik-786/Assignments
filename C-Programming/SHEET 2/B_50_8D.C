#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int getSum(int num) {
	if (num == 0) return 0;
	return num % 10 + getSum(num / 10);
}

int main()
{
	int num;
	scanf("%d", &num);
	int sum = getSum(num);
	printf("%d\n", sum);
	return 0;
}