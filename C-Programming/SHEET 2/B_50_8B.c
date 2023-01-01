#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main()
{
	int a;
	int b;
	scanf("%d%d", &a, &b);
	printf("GCD: %d", gcd(a, b));

	return 0;
}