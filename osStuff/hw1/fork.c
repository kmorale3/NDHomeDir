#include <stdio.h> 
#include <unistd.h> 
 
int main() { 
    pid_t pid = fork(); 
    if (pid == 0) { 
        fork(); 
        printf("child hello\n"); 
    } else { 
        printf("parent hello\n"); 
    } 
    return 0; 
} 