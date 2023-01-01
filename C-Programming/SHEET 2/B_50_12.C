#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

typedef  struct n_o_d_e {
	int data;
	struct n_o_d_e* next;
} Node;

Node *HEAD = 0;
Node *curNode = 0;
void insert(int data) {
	//create data
	Node *temp;

	temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = 0;

	if (!HEAD) {
		HEAD = temp;
		curNode = temp;
	}
	else {
		curNode->next = temp;
		curNode = temp;
	}
}

void deleteNode(int data) {
	if (!HEAD) printf("No data to delete\n");
	else {
		if (data == HEAD->data) {
			HEAD = HEAD->next;
		} else {
			Node *cur = HEAD;
			int found = 0;

			while (cur->next != 0) {
				if (cur->next->data == data) {
					found = 1;
					break;
				}
				cur = cur->next;
			}

			if (found) {
				cur->next = cur->next->next;
				printf("\n[Deleted]\n");
			}
			else {
				printf("\n[No data found]\n");
			}

		}
	}
}

void printList() {
	if (!HEAD)
		printf("\n[List is Empty]\n");
	else
	{
		Node *temp = HEAD;
		while (temp) {
			printf("%d->", temp->data);
			temp = temp->next;
		}
		printf("NULL\n");
	}
}

int searchList(int data) {
	if (!HEAD)
	{
		printf("\n[List is Empty]\n");
		return 0;
	}
	else
	{
		Node *temp = HEAD;
		while (temp) {
			if (temp->data == data) {
				return 1;
				break;
			}
			temp = temp->next;
		}
		return 0;

	}


}

int main()
{
	while (1) {
		printf("1.Insert\n2.Delete\n3.Print List\n4.Search\n5.Exit\nEnter Choice: ");
		int choice;
		scanf("%d", &choice);

		if (choice == 1) {
			int data;
			printf("Enter Data: ");
			scanf("%d", &data);
			insert(data);

		} else if (choice == 2) {
			int data;
			printf("Enter Data: ");
			scanf("%d", &data);
			deleteNode(data);
		} else if (choice == 3) {
			printf("\n");
			printList();
			printf("\n");

		} else if (choice == 4) {
			int data;
			printf("Enter Data: ");
			scanf("%d", &data);
			if (searchList(data))
				printf("\n[Found]\n");
			else {
				printf("\n[ Not Found]\n");
			}

		} else if (choice == 5) {
			break;
		} else {
			printf("\n[Wrong Choice]\n");
		}
	}




	return 0;
}