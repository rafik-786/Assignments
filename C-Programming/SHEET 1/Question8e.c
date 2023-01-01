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

const int  PRIMES_MAX = 1000000 ;

int PRIMES[1000001];
int createSeive()
{
	for (int i = 0; i <= PRIMES_MAX; i++) PRIMES[i] = 1;
	for (int i = 2; i * i <= PRIMES_MAX; i++) {
		if (PRIMES[i]) {
			for (int j = i * i; j <= PRIMES_MAX; j += i) {
				PRIMES[j] = 0;
			}
		}
	}
}
int NO_OF_PRIMES = 785000;
int PRIMES_LIST[785001];

void getPrimesList() {
	createSeive();
	int count = 0;
	for (int i = 2; i < PRIMES_MAX; i++ )
	{
		if (PRIMES[i]) {
			PRIMES_LIST[count] = i;
			count++;
		}
	}

}
int main()
{
	getPrimesList();

	int n;
	inputINT(n);

	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += PRIMES_LIST[i - 1] * PRIMES_LIST[i];
	}

	printINT(ans);

	return 0;
}