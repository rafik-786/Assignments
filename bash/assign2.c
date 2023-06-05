#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <wait.h>


#define PERMS 0666

void p1();
void p2();
void p3();

void sem_wait(int*);
void sem_post(int*);


int *counter;
int *semaphores;
int main() {

	//Param for semaphore
	key_t sem_key = 1000;
	size_t sem_size = sizeof(int) * 3;
	int sem_id = shmget(sem_key, sem_size, IPC_CREAT | PERMS);



	//params for counter
	key_t counter_key = 2000;
	size_t counter_size  = sizeof(int);
	int counter_id = shmget(counter_key, counter_size, IPC_CREAT | PERMS);


	// Attach to the process
	semaphores = (int *)shmat(sem_id, NULL, 0);
	counter = (int *)shmat(counter_id, NULL, 0);

	semaphores[0] = 1; // A
	semaphores[1] = 0; // B
	semaphores[2] = 0; // C

	*counter = 100; // counter

	pid_t pid;
	for (int i = 0; i < 3; i++) {
		pid = fork();
		if (pid == 0) {
			if (i == 0) p1();
			else if (i == 1) p2();
			else if ( i == 2 ) p3();

		}
	}


	wait(NULL);
	shmdt(semaphores);
	shmdt(counter);
	shmctl(sem_id, IPC_RMID, NULL);
	shmctl(counter_id, IPC_RMID, NULL);

	return 0;
}

void sem_wait(int *sem) {
	while ((*sem) <= 0);
	(*sem)--;
}

void sem_post(int *sem) {
	(*sem)++;
}

void p1() {
	while (1) {
		sem_wait(&semaphores[0]);
		printf("A ");
		fflush(stdout);
		sem_post(&semaphores[1]);
	}
	shmdt(semaphores);
	shmdt(counter);
}
void p2() {
	int turn = 0;
	while (1) {
		sem_wait(&semaphores[1]);
		if (*counter <= 0) {
			break;
		}
		printf("B ");
		fflush(stdout);
		if (turn == 0) {
			turn = 1;
			sem_post(&semaphores[2]);
		} else {
			(*counter)--;
			printf("\n");
			fflush(stdout);
			turn = 0;
			sem_post(&semaphores[0]);
		}
	}
	shmdt(semaphores);
	shmdt(counter);
}
void p3() {
	int turn = 0;
	while (1) {
		sem_wait(&semaphores[2]);
		if ((*counter) <= 0) {
			break;
		}
		printf("C ");
		fflush(stdout);
		if (turn == 0) {
			turn  = 1;
			sem_post(&semaphores[2]);
		} else {
			turn = 0;
			sem_post(&semaphores[0]);
		}
	}
	shmdt(semaphores);
	shmdt(counter);
}