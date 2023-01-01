#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int fibonacci(int n) {
	if (n == 0 || n == 1) return n;
	else return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
	printf("%d", fibonacci(8));

	return 0;
}