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
double fact[200];

int main()
{

	fact[1] = 1;
	for (int i = 2; i <= 200; i++)
	{
		fact[i] = i * fact[i - 1];
	}

	double n;
	inputDOUBLE(n);
	double num = n * n;
	int term = 100, i = 2;
	double sign = +1;
	double ans = 1;
	while (term--)
	{
		ans -= (num / fact[i]) * sign;
		num *= n; num *= n;
		i += 2;
		sign *= -1;
	}
	printDOUBLE(ans);


	return 0;
}