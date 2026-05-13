#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5

pthread_t philosophers[N];
sem_t forks[N];
sem_t room;

void* dine(void* arg) {
    int phil = *(int*)arg;

    for (int i = 0; i < 3; i++) {
        printf("Philosopher %d is thinking\n", phil);
        sleep(1);

        sem_wait(&room);

        sem_wait(&forks[phil]);
        sem_wait(&forks[(phil + 1) % N]);

        printf("Philosopher %d is eating\n", phil);
        sleep(2);

        sem_post(&forks[phil]);
        sem_post(&forks[(phil + 1) % N]);

        sem_post(&room);

        printf("Philosopher %d finished eating\n", phil);
    }

    pthread_exit(NULL);
}

int main() {
    int i;
    int phil_num[N];

    sem_init(&room, 0, N - 1);

    for (i = 0; i < N; i++) {
        sem_init(&forks[i], 0, 1);
    }

    for (i = 0; i < N; i++) {
        phil_num[i] = i;
        pthread_create(&philosophers[i], NULL, dine, &phil_num[i]);
    }

    for (i = 0; i < N; i++) {
        pthread_join(philosophers[i], NULL);
    }

    printf("All philosophers have finished eating.\n");

    return 0;
}
