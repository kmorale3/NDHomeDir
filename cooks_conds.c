
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

pthread_mutex_t mutexOrder;
pthread_cond_t orderFilled;
int order = 0;

void *order_filling(void *arg) {
    for (int i = 0; i < 6; i++) {
        pthread_mutex_lock(&mutexOrder);
        order += 1;
        printf("Chef prepared dish... %d\n", order);
        if (order % 3 == 0) {
            pthread_cond_broadcast(&orderFilled);
        } else {
            printf("No order of 3 dishes completed by Chef. Customer waiting...\n");
        }
        pthread_mutex_unlock(&mutexOrder);
        sleep(1);
    }
}

void *customer(void *arg) {
    int dishes_to_pick = 3;
    while (dishes_to_pick > 0) {
        pthread_mutex_lock(&mutexOrder);
        while (order < dishes_to_pick) {
            printf("No order of %d dishes completed by Chef. Customer waiting...\n", dishes_to_pick);
            pthread_cond_wait(&orderFilled, &mutexOrder);
        }

        order -= dishes_to_pick;
        printf("Customer got order of %d dishes. Now waiting: %d\n", dishes_to_pick, order);
        pthread_mutex_unlock(&mutexOrder);

        dishes_to_pick = 0;
    }
}

int main(int argc, char *argv[]) {
    pthread_t th[3];
    pthread_mutex_init(&mutexOrder, NULL);
    pthread_cond_init(&orderFilled, NULL);

    for (int i = 0; i < 3; i++) {
        if (i == 2) {
            if (pthread_create(&th[i], NULL, &order_filling, NULL) != 0) {
                perror("Failed to create thread");
            }
        } else {
            if (pthread_create(&th[i], NULL, &customer, NULL) != 0) {
                perror("Failed to create thread");
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread");
        }
    }

    pthread_mutex_destroy(&mutexOrder);
    pthread_cond_destroy(&orderFilled);

    return 0;
}
