#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <wait.h>
#include <time.h>

#define PERMS 0666
#define ARRAY_SIZE 100

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

int maxElement(int *arr, int size);
int minElement(int *arr, int size);
float average(int *arr, int size);

int main()
{
	// Params for shared data
	key_t data_key = 3050;
	size_t data_size = sizeof(int) * ARRAY_SIZE;
	int *shared_data;


	// Params for shared result
	key_t res_key = 4050;
	size_t res_size = sizeof(float) * 3;
	float *shared_result;

	// Params for Shared mutex
	key_t mutex_key = 5050;
	size_t mutex_size = sizeof(int);
	int *shared_mutex;


	//create memory segment for data
	size_t data_id = shmget(data_key, data_size, PERMS | IPC_CREAT);

	//create memory segment for result
	size_t res_id = shmget(res_key, res_size, PERMS | IPC_CREAT);

	//create memory segment for mutex
	size_t mutex_id = shmget(mutex_key, mutex_size, PERMS | IPC_CREAT);


	//check for memory segment failure
	if (data_id == -1 || res_id == -1 || mutex_id == -1 ) {
		perror("\nCould not create Segment\n");
		return EXIT_FAILURE;
	}


	// Attach for memory segment to the process
	shared_data = (int*)shmat(data_id, NULL, 0);
	shared_result = (float*)shmat(res_id, NULL, 0);
	shared_mutex = (int*)shmat(mutex_id, NULL, 0);



	//check for memory attachment failure
	if (shared_data == (int*) - 1 || shared_result == (float*) - 1 || shared_mutex == (int*) - 1 ) {
		perror("\nCould not attach segment\n");
		return EXIT_FAILURE;
	}




	//Initializtion of mutex
	*shared_mutex = 0;


	pid_t pid = fork();

	//check for child process creation failure
	if (pid == -1) {
		perror("\nCould not create child Process\n");
		return EXIT_FAILURE;
	}
	if (pid == 0) {

		/* Inside Child Process */
		while ((*shared_mutex == 0));
		printf("\n***Inside Child  Process***\n");
		printf("\nCalulating MAX , MIN , AVERAGE\n");

		shared_result[0] = (float)maxElement(shared_data, ARRAY_SIZE);
		shared_result[1] = (float)minElement(shared_data, ARRAY_SIZE);
		shared_result[2] = average(shared_data, ARRAY_SIZE);
		printf("\nCalulation Complete of MAX , MIN , AVERAGE\n");
		*shared_mutex = 0;

		shmdt(shared_result);
		shmdt(shared_data);
		shmdt(shared_mutex);
		exit(0);

	} else {

		printf("***Inside Parent Process***\n");
		// generate random 100 numbers
		time_t t1;
		srand ( (unsigned) time (&t1));

		printf("\nGenerating 100 random numbers...\n");
		for (int i = 0; i < ARRAY_SIZE; i++) {
			shared_data[i] = rand() % (int)1e5;
			printf("%d ", shared_data[i]);
		}

		printf("\nGeneration Complete....\n");
		*shared_mutex = 1;
		while ((*shared_mutex == 1));
		printf("\n***Inside Parent Process***\n");
		printf("Max: %d\nMin: %d\nAverage:%f \n", (int)shared_result[0], (int)shared_result[1], shared_result[2]);

		shmdt(shared_result);
		shmdt(shared_data);
		shmdt(shared_mutex);
	}

	return 0;
}

int maxElement(int *arr, int size) {
	int res = arr[0];
	for (int i = 0; i < size; i++) res = MAX(res, arr[i]);
	return res;
}

int minElement(int *arr, int size) {

	int res = arr[0];
	for (int i = 0; i < size; i++) res = MIN(res, arr[i]);
	return res;
}

float average(int *arr, int size) {
	float res = 0.0f;
	for (int i = 0; i < size; i++) res += (float)arr[i];
	return res / size;
}