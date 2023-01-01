#include <stdio.h>
#include <stdlib.h>

#define CHAR_LENGTH 100

#define CRORE 10000000
#define MILLION 1000000
#define LAKH  100000
#define THOUSAND 1000
#define HUNDRED 100


char twoDigit[][CHAR_LENGTH] = {
	"",
	"",
	"Twenty",
	"Thirty",
	"Fourty",
	"Fifty",
	"Sixty",
	"Seventy",
	"Eighty",
	"Ninty"
};

char twoDigitSpecial[][CHAR_LENGTH] = {
	"Ten",
	"Eleven",
	"Twelve",
	"Thirteen",
	"Fourteen",
	"Fifteen",
	"Sixteen",
	"Seventeen",
	"Eighteen",
	"Ninteen",

};

char singleDigit[][CHAR_LENGTH] = {
	"",
	"One",
	"Two",
	"Three",
	"Four",
	"Five",
	"Six",
	"Seven",
	"Eight",
	"Nine"
};

char *concate(char *string1, char *string2) {
	int len1 = 0, len2 = 0;
	while (string1[len1] != '\0') len1++;
	while (string2[len2] != '\0') len2++;
	char* output = (char*)malloc(len1 + len2);
	sprintf(output, "%s%s", string1, string2);
	return output;
}


char *getTwoDigitString(int num) {
	if (num <= 9 ) return singleDigit[num];
	else if (num >= 10 && num < 20) return twoDigitSpecial[num - 10];
	else {
		int quotient = num / 10;
		char *ans = concate(twoDigit[num / 10], " ");
		ans =  concate(ans, singleDigit[num % 10]);
		return ans;
	}
}

char *getThreeDigitString(int num) {
	char *output;
	if (num >= 100) {
		output =  getTwoDigitString(num / 100);
		output = concate(output, " Hundred ");
		output = concate(output, getTwoDigitString(num % 100));
		return output;
	} else {
		return getTwoDigitString(num);
	}
}

char  *convertIndian(int num) {

	char *ans = "";
	if (num >= CRORE)
	{
		ans = getTwoDigitString(num / CRORE);
		ans = concate(ans, " Crore ");
		num = num % CRORE;
	}
	if (num >= LAKH) {
		ans  = concate(ans, getTwoDigitString(num / LAKH));
		ans  = concate(ans, " Lakh ");
		num = num % LAKH;
	}
	if (num >= THOUSAND)
	{
		ans  = concate(ans, getTwoDigitString(num / THOUSAND));
		ans = concate(ans, " Thousand  ");
		num = num % THOUSAND;
	}
	if (num < THOUSAND) {
		ans  = concate(ans, getThreeDigitString(num));
	}

	return ans;
}

char *convertInternation(int num) {

	char *output = "";
	if (num >= MILLION) {
		output = concate(output, getThreeDigitString(num / MILLION));

		output = concate(output, " Million ");
		num = num % MILLION;

	}
	if (num >= THOUSAND)
	{
		output = concate(output, getThreeDigitString(num / THOUSAND));

		output = concate(output, " Thousand ");
		num = num % THOUSAND;
	}
	if (num < THOUSAND) {
		output  = concate(output, getThreeDigitString(num));
	}
	return output;



}

int main()
{

	int num;
	printf("Please Enter The Number: ");
	scanf("%d", &num);

	printf("\n[INDIAN FORMAT]: ");
	char *indian = convertIndian(num);
	printf("%s\n", indian );

	printf("\n[INTERNATIONAL FORMAT]: ");
	char *international = convertInternation(num);
	printf("%s\n", international );


	return 0;
}