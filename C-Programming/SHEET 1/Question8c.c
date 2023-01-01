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


#define ITERATION 10

double getPower(double a, int n) {
	double ans = 1.0;
	while (n > 0) {
		if (n & 1) ans *= a;
		n = n >> 1;
		a = a * a;
	}
	return ans;
}
double getLog(double x) {

	double ans = 0.0;
	for (int i = 1; i <= ITERATION; i++) {
		if (i & 1) {
			ans += getPower(x, i) / i;
		}
		else {
			ans -= getPower(x, i) / i;
		}

	}
	return ans;
}
int main()
{

	double x;
	inputDOUBLE(x);
	printDOUBLE(getLog(x));

	return 0;
}