#include <stdio.h>
void getEuclidGCD(int a, int b) {
	printf("Remainder List: ");
	while (b != 0) {
		int temp = a;
		a = b;
		b = temp % b;
		printf("%d ", a);
	}
	printf("\nGCD: %d\n", a);

}


void getFactorizationGCD(int a, int b) {

	int lcm = 1;
	int min = a > b ? b : a;
	int gcd = (a * b);
	for (int i = 2; i <= min; i++) {
		while (a % i == 0 && b % i == 0) {
			printf("%d|%d %d|\n", i, a, b);
			lcm *= i;
			a /= i;
			b /= i;
		}
	}
	printf("|%d %d|\n", a, b);
	lcm = lcm * a * b;
	gcd = gcd / lcm;
	printf("\nGCD: %d\n", gcd);
}

int main()
{

	int a = 27972;
	// printf("Please Enter The First Number: ");
	scanf("%d", &a);

	int b = 8820;
	// printf("Please Enter The Second Number: ");
	scanf("%d", &b);

	printf("\n[Euclide GCD]\n");
	getEuclidGCD(a, b);

	printf("\n[Factorization GCD]\n");
	getFactorizationGCD(a, b);

	return 0;
}