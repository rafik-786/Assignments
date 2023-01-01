#include <stdio.h>
#include <stdio.h>
#include <math.h>
#define ll long long int
#define inputINT(num) scanf("%d",&num);
#define inputLONG(num)scanf("%ld",&num);
#define inputDOUBLE(num) scanf("%lf",&num);
#define printDOUBLE(num) printf("%.5e ",num);
#define prinntINT(num) printf("%ld ",num);
#define output(STRING) printf(STRING);
#define printLine printf("\n");


double fibFormula(int num) {

	double ans = 0;
	double rt5 = sqrt(5);
	double constant = 1 / rt5;
	double fp = constant * pow((1 + rt5) / 2, num);
	double lp = constant * pow((1 - rt5) / 2, num);
	ans = fp - lp;
	return ans;
}


ll fib(int num) {
	ll a = 0, b = 1, c = 0;

	for (int i = 1; i <= num; i++) {
		c = a + b;
		a = b;
		b = c;
	}

	return a;
}

int main()
{


	int num;
	inputINT(num);



	output("Actual Output: ");
	prinntINT(fib(num));
	printLine;
	output("Formula Output: ");
	printf("%.lf", fibFormula(num));
	printLine;
	double diff  = fib(num) - fibFormula(num);
	output("Difference: ");
	printDOUBLE(diff);
	printLine;
	printLine;


	return 0;
}