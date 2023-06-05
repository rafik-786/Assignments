#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <time.h>
#include <unistd.h>

#define READERS 10
#define WRITERS 5

sem_t writer;
int data = 1;
int readerCount = 0;


pthread_mutex_t mutex;

void readerFn();
void writerFn();
int main()
{

	pthread_t readers[READERS], writers[WRITERS];
	pthread_mutex_init(&mutex, NULL);

	sem_init(&writer, 0, 1);

	for (int  i = 0; i < READERS; i++)
		pthread_create(&readers[i], NULL, (void*)&readerFn, (void*)&i);

	for (int i = 0; i < WRITERS; i++)
		pthread_create(&writers[i], NULL, (void*)&writerFn, (void*)&i);

	for (int i = 0; i < READERS; i++)
		pthread_join(readers[i], NULL);

	for (int i = 0; i < WRITERS; i++)
		pthread_join(writers[i], NULL);

	pthread_mutex_destroy(&mutex);
	sem_destroy(&writer);
	return 0;
}

void readerFn(void *readerNo) {

	pthread_mutex_lock(&mutex);
	readerCount++;

	if (readerCount == 1) {
		sem_wait(&writer);
	}

	pthread_mutex_unlock(&mutex);
	//Reading
	printf("Reader %d : => Data: %d \n", *((int*)readerNo), data);
	pthread_mutex_lock(&mutex);
	readerCount--;

	if (readerCount == 0) {
		sem_post(&writer);
	}
	pthread_mutex_unlock(&mutex);

}

void writerFn(void *writeNo) {
	sem_wait(&writer);
	//writing
	data = data << 1;
	printf("writer %d modified data to: %d\n", *((int*)writeNo), data);
	sem_post(&writer);
}