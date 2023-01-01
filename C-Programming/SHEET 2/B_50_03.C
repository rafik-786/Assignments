#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int readline(char *str, int size) {
	char temp;
	int count = 0;
	do {
		scanf("%c", &temp);
		str[count] = temp;
		count++;
	} while (temp != '#');
	str[count - 1] = '\0';
	return count - 1;
}

char **split(char *str, int *totalWords) {

	// puts(str);
	//find size
	int size = 0;
	while (str[size] != '\0') {
		size++;
	}
	// printf("Size: %d\n", size );

	char **words;

	words = (char**)malloc(sizeof(char*) * 1000);

	int wordCount = 1;
	int len = 0;
	int lpos = 0;
	int cpos = 0;
	for (int i = 0; i < size; i++) {
		if ((str[i] == ' ' || str[i] == '\n') && (str[i + 1] != ' ')) {
			cpos = i - 1;

			words[wordCount] = (char*)malloc(sizeof(char) * (len + 1));

			for (int j = 0; j < len; j++) {
				words[wordCount][j] = str[lpos + j];
			}
			words[wordCount][len] = '\0';

			// printf("[\"%s\"][Length: %d ][ %d - %d]\n", words[wordCount], len, lpos, cpos);
			lpos = i + 1;
			len = -1;
			wordCount++;
		}
		len++;

	}

	*totalWords = size > 0 ? wordCount - 1 : 0;
	// printf("words: %d\n", *totalWords );

	return words;
}

int checkArticle(char *str) {
	int size = 0;
	while (str[size] != '\0') {
		size++;
	}
	int ans = 0;

	if (size > 3) {
		return 0;
	}
	else if (size == 1) {
		ans = str[0] == 'a' || str[0] == 'A';
	}
	else if (size == 2) {
		ans += str[0] == 'a' || str[0] == 'A';
		ans &=  str[1] == 'n' || str[1] == 'N';
	}
	else if (size == 3) {
		ans += str[0] == 't' || str[0] == 'T';
		ans &=  str[1] == 'h' || str[1] == 'H';
		ans &=  str[2] == 'e' || str[2] == 'E';
	}

	return ans;
}

int main()
{
	char str[1000];
	int size = readline(str, 1000);
	int wordCount;
	char **words = split(str, &wordCount);;

	//count article
	int countArticle = 0;
	int upcase = 0;

	for (int i = 1; i <= wordCount; i++)
	{
		if (checkArticle(words[i])) {
			countArticle++;
		}

		// uppcase or not
		if ( !(words[i][0] & (1 << 5))) {
			upcase++;
			printf("%s\n", words[i]);
		}



	}
	// free(words);

	printf("Article Count: %d\n", countArticle);
	printf("Uppercase Count: %d\n", upcase);


	return 0;
}