//with locks

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <semaphore.h>

#define THREAD_NUM 4

int fuel = 50;

sem_t s;


void* routine(void* args) {
    sem_wait(&s);
    fuel += 50;
    printf("Current value is %d\n", fuel);
    sem_post(&s);
}


int main(int argc, char *argv[]) {
    pthread_t th[THREAD_NUM];
    sem_init(&s, 0, 1);
    int i;
    for (i = 0; i < THREAD_NUM; i++) {
        if (pthread_create(&th[i], NULL, &routine, NULL) != 0) {
            perror("Failed to create thread");
        }
    }

    for (i = 0; i < THREAD_NUM; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread");
        }
    }
    return 0;
}