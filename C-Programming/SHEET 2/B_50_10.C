#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int main()
{
	char str1[100];
	gets(str1);

	char str2[100];
	gets(str2);

	int size1 = 0;
	while (str1[size1] != '\0') {
		size1++;
	}

	int size2 = 0;
	while (str2[size2] != '\0') {
		size2++;
	}
	int found = 0;
	int indx = -1;
	for (int i = 0; i < size1 - size2; i++) {

		if (str1[i] == str2[0]) {
			// might exist
			found = 1;
			for (int j = 0; j < size2; j++) {
				// others do not match
				if (str1[i + j] != str2[j])
				{
					found = 0;
					break;
				}

			}
			if (found) {
				indx = i; break;
			}
		}

	}

	printf("%s\n", found ? "[PRESENT]" : "[NOT PRESENT]" );
	printf("%d\n", found ? indx : -1 );

	return 0;
}