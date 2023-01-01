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

int main()
{
	double b;
	int p;
	inputDOUBLE(b);
	inputINT(p);
	if (b == 0 && p <= 0)
		printf("Undefined\n");
	else if (b == 0 && p > 0)
		printf("0\n");
	else if (b == -1 && p < 0)
		printf("-1\n");
	else if (b < -1 && p <= -1) {
		double ans = 1;
		p = -p;
		for (int i = 0; i < p; i++)
			ans *= b;
		printf("%le\n", 1.0 / ans );
	}
	else {
		double ans = 1;
		for (int i = 0; i < p; i++)
			ans *= b;
		printDOUBLE(ans);
	}


	return 0;
}