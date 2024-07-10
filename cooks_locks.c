#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <errno.h> 
pthread_mutex_t mutexOrder; 
int order = 0; 
void* order_filling(void* arg) { 
 for (int i = 0; i <= 2; i++) { 
 pthread_mutex_lock(&mutexOrder); 
 order += 1; 
 printf("Chef Filled order... %d\n", order); 
 pthread_mutex_unlock(&mutexOrder); 
 //sleep(1); 
 } 
} 
void* customer(void* arg) { 
 pthread_mutex_lock(&mutexOrder); 
 if (order >=3){ 
 order -= 3; 
 printf("Customer got order of three dishes. Now waiting: %d\n", order); 
 } else { 
 printf("No prepared dish \n"); 
 } 
 pthread_mutex_unlock(&mutexOrder); 
} 
int main(int argc, char* argv[]) { 
 pthread_t th[2]; 
 pthread_mutex_init(&mutexOrder, NULL); 
 for (int i = 0; i <= 2; i++) { 
 if (i == 1) { 
 if (pthread_create(&th[i], NULL, &order_filling, NULL) != 0) { 
 perror("Failed to create thread"); 
 }
 } else { 
 if (pthread_create(&th[i], NULL, &customer, NULL) != 0) { 
 perror("Failed to create thread"); 
 } 
 } 
 } 
 for (int i = 0; i <= 2; i++) { 
 if (pthread_join(th[i], NULL) != 0) { 
 perror("Failed to join thread"); 
 } 
 } 
 pthread_mutex_destroy(&mutexOrder); 
 return 0; 
} 
