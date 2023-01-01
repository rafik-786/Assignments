#include <stdio.h>
#define ld long double
#define ll long long int
#define inputINT(num) scanf("%d",&num);
#define inputLONG(num)scanf("%ld",&num);
#define inputDOUBLE(num) scanf("%lf",&num);
#define printDOUBLE(num) printf("%lf ",num);
#define prinntINT(num) printf("%ld ",num);
#define output(STRING) printf(STRING);
#define printLine printf("\n");

int main()
{
	int n;
	inputINT(n);
	int fact = 1;
	double ans = 0;
	for (int i = 1; i <= n; i++) {
		fact *= i;
		ans += (double)i / fact;

	}
	printDOUBLE(ans);
	return 0;
}