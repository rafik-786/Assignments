#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>


#define LIMIT 3

typedef struct s_t_u_d_e_n_t
{
	char *name;// --> 4/8byt
	int roll;
	int *marks;
	int total;
	float avg;

} Student;

void printData(Student *data, int size) {

	for (int i = 0; i < size; i++) {

		printf("[Student %d]\n", (i + 1));
		printf("Name:%s", data[i].name);
		printf("Roll:%d\n", data[i].roll);
		printf("[Marks:] ");
		for (int j = 0; j < 5; j++) {
			printf("%d ", data[i].marks[j]);
		}
		printf("\n\n");

	}
}
void swap(Student *s1, Student *s2) {
	char *name = s1->name;
	int roll = s1->roll;
	int *marks = s1->marks;
	int total = s1->total;
	float avg = s1->avg;

	s1->name = s2->name;
	s1->roll = s2->roll;
	s1->marks = s2->marks;
	s1->avg = s2->avg;
	s1->total = s2->total;


	s2->name = name;
	s2->roll = roll;
	s2->marks = marks;
	s2->avg = avg;
	s2->total = total;

}

int main()
{

	Student data[LIMIT];
	char useless;
	for (int i = 0; i < LIMIT; ++i)
	{
		// input name
		data[i].name = malloc(sizeof(char) * 30);
		fgets(data[i].name, 30, stdin);

		// input roll
		scanf("%d", &data[i].roll);

		// input 5 marks
		data[i].marks = malloc(sizeof(int) * 5);

		for (int j = 0 ; j < 5; j++) {
			scanf("%d", &data[i].marks[j]);
		}

		scanf("%c", &useless); // don't forget


	}

	printData(data, LIMIT);

	for (int i = 0; i < LIMIT; i++) {
		int sum = 0;
		for (int j = 0; j < 5; j++) {
			sum += data[i].marks[j];
		}
		data[i].total = sum;
	}

	printf("\nAverage\n");
	for (int i = 0; i < LIMIT; i++) {
		data[i].avg = data[i].total / 5.0;
		printf("[Student %d]: %f\n", (i + 1), data[i].avg);
	}




	printf("\nSorted Data:\n");

	for (int i = 0; i < LIMIT; i++)
	{
		for (int j = 0; j < LIMIT - 1; j++) {
			// printf("%d %d\n", data[j].total, data[j + 1].total);
			if (data[j].total < data[j + 1].total) {
				// printf("Swapping\n\n");
				swap(&data[j], &data[j + 1]);
			}
		}
	}

	printData(data, LIMIT);

	return 0;
}