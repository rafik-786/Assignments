#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>


int main()
{
	char hex[] = {
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
	};

	char *ans = (char*)malloc(sizeof(char) * 100);

	float in = 95.1234;
	scanf("%f", &in);

	float diff = in - floor(in);
	int val = in;
	int b = 16;
	scanf("%d", &b);
	int k = 0;
	int rem;
	do {
		rem = val % b;
		ans[k++] = hex[rem];
		val = val / b;

	} while (val >= b);
	ans[k] = hex[val];

	int l = 0;
	int h = k ;
	while (l < h) {
		int temp = ans[l];
		ans[l] = ans[h];
		ans[h] = temp;
		l++;
		h--;
	}
	if (diff) {
		ans[++k] = '.';
		for (int i = 1; i <= 10; i++) {
			float temp = diff * b;
			ans[++k] = hex[(int)temp];
			diff = temp - floor(temp);
			if (diff == 0) break;
		}
	} else {
		ans[k + 1] = '\0';
	}
	printf("%s\n", ans);

	return 0;
}