#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define CHAR_LENGTH 30
typedef struct l_i_b_r_a_r_y {
	int accessionNo;
	char *title;
	char *author;
	float price;
	int isIssued;
} Library;

Library *Books;
int count;

void init(void) {
	Books = (Library*)malloc(sizeof(Books) * 1000);
	count = 0;
}

void showBook(Library book) {
	printf("\n------------[BOOK-INFORMATION]-------------");
	printf("\nAccession No. : %d", book.accessionNo);
	printf("\nTitle: %s", book.title);
	printf("Author: %s", book.author);
	printf("Price: $%f", book.price);
	printf("\nIssued: %s\n", book.isIssued ? "YES" : "NO");
	printf("----------------------------------------------\n");
}

void addBook(void) {
	printf("\nEnter Accession No: ");
	scanf("%d", &Books[count].accessionNo);

	char useless;
	scanf("%c", &useless);
	printf("\nEnter Title: ");
	Books[count].title = malloc(sizeof(char) * CHAR_LENGTH);
	fgets(Books[count].title, CHAR_LENGTH, stdin);

	printf("\nEnter Author: ");
	Books[count].author = malloc(sizeof(char) * CHAR_LENGTH);
	fgets(Books[count].author, CHAR_LENGTH, stdin);


	printf("\nEnter Price: ");
	scanf("%f", &Books[count].price);

	printf("\nIs Issued?(0/1): ");
	scanf("%d", &Books[count].isIssued);


	printf("\n[BOOK ADDED]\n");
	showBook(Books[count]);

	count++;
}

void display(void) {
	if (count) {
		printf("\nEnter Accession No: ");
		int an;
		scanf("%d", &an);

		for (int i = 0; i < count; i++) {
			if (Books[i].accessionNo == an) {
				showBook(Books[i]);
				return;
			}
		}

		printf("\n[Entry Not Found]\n");
	} else {
		printf("\n[No Book Available]\n");
	}

}
int checkEquality(char *book1, char *book2) {
	int n = 0;
	int m = 0;

	while (book1[n] != '\0') {
		n++;
	}
	while (book2[m] != '\0') {
		m++;
	}

	if (n != m) return 0;
	else {
		int i = 0, j = 0;
		while (i < n && j < m) {
			if (book1[i] != book2[j]) return 0;
			i++;
			j++;
		}
		return 1;
	}
}
void listAuthor(void) {
	if (count) {
		char useless;
		scanf("%c", &useless);
		printf("\nEnter Author Name: ");
		char* author = malloc(sizeof(char) * CHAR_LENGTH);
		fgets(author, CHAR_LENGTH, stdin);

		printf("\n====================[List]==================\n");
		for (int i = 0; i < count; i++) {
			if (checkEquality(Books[i].author, author)) {
				showBook(Books[i]);
			}
		}

		printf("\n===============================================\n");
	} else {
		printf("\n[No Book Available]\n");
	}


}
void swap(Library *book1, Library *book2) {
	int accessionNo = book1->accessionNo;
	char *title = book1->title;
	char *author = book1->author;
	float price = book1->price;
	int isIssued = book1->isIssued;

	book1->accessionNo = book2->accessionNo;
	book1->title = book2->title;
	book1->author = book2->author;
	book1->price = book2->price;
	book1->isIssued = book2->isIssued;


	book2->accessionNo = accessionNo;
	book2->title = title;
	book2->author = author;
	book2->price = price;
	book2->isIssued = isIssued;


}
void sortAndDisplay(void) {

	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count - 1; j++) {
			if (Books[j].accessionNo > Books[j + 1].accessionNo) {
				swap(&Books[j], &Books[j + 1]);
			}
		}
	}

	printf("\n====================[List]==================\n");
	for (int i = 0; i < count; i++) {
		showBook(Books[i]);
	}


}

int main()
{
	init();

	while (1) {
		printf("[Menu]\n");
		printf("1.Add Book\n");
		printf("2.Display Book Info\n");
		printf("3.List all Books of an author\n");
		printf("4.List count of Books\n");
		printf("5.List all books in order of accessionNo\n");
		printf("6.Exit\n");

		int choice;
		printf("Enter choice: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			addBook();
			break;
		case 2:
			display();
			break;
		case 3:
			listAuthor();
			break;
		case 4:
			printf("\nTotal Number of Books available: %d\n", count);
			break;
		case 5:
			sortAndDisplay();
			break;
		case 6:
			printf("\n\n[Thank You]\n\n");
			exit(1);
			break;
		default:
			printf("\n[Wrong Choice]\n");
		}
		printf("\n");

	}


	return 0;
}