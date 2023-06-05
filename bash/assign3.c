#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <time.h>
#include <unistd.h>

#define MAX_ITEM 10
#define BUFFER_SIZE 10

sem_t full;
sem_t empty;

int in = 0;
int out = 0;

int buffer[BUFFER_SIZE];

pthread_mutex_t mutex;

void producerFn();
void consumerFn();
int main()
{
	time_t t1;
	srand((unsigned)time(&t1));

	pthread_t producer, consumer;
	pthread_mutex_init(&mutex, NULL);


	sem_init(&empty, 0, MAX_ITEM);
	sem_init(&full, 0, 0);

	pthread_create(&consumer, NULL, (void*)&consumerFn, NULL);
	pthread_create(&producer, NULL, (void*)&producerFn, NULL);

	pthread_join(producer, NULL);
	pthread_join(consumer, NULL);

	pthread_mutex_destroy(&mutex);
	sem_destroy(&empty);
	sem_destroy(&full);
	return 0;
}

void producerFn() {
	for (int  i = 0; i < MAX_ITEM; i++) {
		sleep(1);
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		buffer[in] = rand() % (int)1e4;
		printf("Produced item %d: %d\n", in , buffer[in]);
		in = (in + 1) % BUFFER_SIZE;
		pthread_mutex_unlock(&mutex);
		sem_post(&full);
	}

}

void consumerFn() {
	for (int  i = 0; i < MAX_ITEM; i++) {
		sleep(1);
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		printf("Consumed item %d: %d\n", out, buffer[out]);
		out = (out + 1) % BUFFER_SIZE;
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
	}
}