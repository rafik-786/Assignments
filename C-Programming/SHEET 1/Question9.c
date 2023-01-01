#include <stdio.h>
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

#define SIZE 100000
int seive[SIZE];

void createSeive() {


	for (int i = 0; i < SIZE; i++) seive[i] = 1;
	for (int i = 2; i * i <= SIZE; i++) {
		if (seive[i]) {
			for (int j = i * i; j <= SIZE; j += i) {
				seive[j] = 0;
			}
		}
	}

}

int main()
{
	createSeive();

	int n;
	inputINT(n);

	for (int i = 2; i < n; i++) {
		if (seive[i]) prinntINT(i);
	}



	return 0;
}