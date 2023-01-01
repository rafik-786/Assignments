#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int getBinary(int num) {
	if (num == 0 || num == 1) return num;
	return 10 * getBinary(num >> 1) + (num & 1);
}

int main()
{
	int num;
	scanf("%d", &num);
	int ans = getBinary(num);
	printf("%d", ans);

	return 0;
}