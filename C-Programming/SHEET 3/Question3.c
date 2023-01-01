#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define LIMIT 6
#define NAME_SIZE 30


typedef struct c_u_s_t_o_m_e_r {
	char *name;
	int accountNumber;
	float balance;

} Customer;

void printCustomerData(Customer *data, int size) {

	for (int i = 0; i < size; i++) {

		printf("[Customer: %d]\n", (i + 1));

		//name
		printf("%s", data[i].name);
		// Account Number
		printf("%d\n", data[i].accountNumber);

		//balance
		printf("%f\n", data[i].balance);

	}
}

Customer bank[LIMIT];

void CustomerBalanceLessThan1000(Customer *bank, int size) {
	printf("\nCustomers{ balance less than 1000}\n");

	Customer extract[size];
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (bank[i].balance < 1000) {
			extract[count].name = bank[i].name;
			extract[count].accountNumber = bank[i].accountNumber;
			extract[count].balance = bank[i].balance;
			count++;
		}
	}
	printCustomerData(extract, count);
}
int search(int accountNumber, Customer *data, int size) {
	for (int i = 0; i < size; i++) {
		if (data[i].accountNumber == accountNumber) return i;
	}
	return -1;
}

int main()
{

	char useless;

	//get data for each customer
	for (int i = 0; i < LIMIT; i++) {

		//assign memory for name
		bank[i].name = (char*) malloc(sizeof(char) * NAME_SIZE);

		//get name
		fgets(bank[i].name, NAME_SIZE, stdin);


		//get Account Number
		scanf("%d", &bank[i].accountNumber);

		//get balance
		scanf("%f", &bank[i].balance);
		scanf("%c", &useless);
	}

	// printCustomerData(bank, LIMIT);

	CustomerBalanceLessThan1000(bank, LIMIT);

	int accountNumber;
	// printf("Enter accountNumber:" );
	scanf("%d", &accountNumber);

	float amount;
	// printf("Enter amount");
	scanf("%f", &amount);

	int code;
	// printf("0.WithDraw\n1.Deposit\nEnter Choice");
	scanf("%d", &code);


	if (code == 0) {
		//deposit
		int indx = search(accountNumber, bank, LIMIT);
		if ( indx != -1) {
			bank[indx].balance += amount;
			printf("index-%d", indx);
		} else {
			printf("Account Not Found\n");
		}

	} if (code == 1) {
		int indx = search(accountNumber, bank, LIMIT);
		if ( indx != -1) {
			if (amount > bank[indx].balance) {
				printf("Insuffient balance to make this transaction\n");
			} else {
				bank[indx].balance -= amount;
				printf("Balance Updated\n");
			}
		} else {
			printf("Account Not Found\n");
		}

	}



	printCustomerData(bank, LIMIT);









	return 0;
}


/*

Apple wala
121
1230.1
Banna wala
122
130.1
Cat wala
123
150.1
Dog wala
124
1600.2
Elephant wala
124
170.3
Flower wala
125
123.5
125
127
1

*/