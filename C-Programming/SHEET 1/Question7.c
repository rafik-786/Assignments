#include <stdio.h>
#define input(num) scanf("%d",&num);
#define print(b) printf(b);

#define ll long long int

ll getEuclidLCM(ll a, ll b) {
	ll lcm = a * b;
	while (b != 0) {
		int temp = a;
		a = b;
		b = temp % b;
	}

	return lcm / a;

}


int main()
{

	int n;
	// printf("Enter the number of Numbers:");
	input(n);

	int num;
	ll lcm   = 1 ;
	for (int i = 0; i < n; i++) {
		input(num);
		if (num < 1) {
			print("Cannot be calculated\n");
			return 0;
		} else {
			lcm = getEuclidLCM(lcm, num);
		}
	}

	printf("LCM: %d\n", lcm);
}