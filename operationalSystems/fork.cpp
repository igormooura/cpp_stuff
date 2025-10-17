#include <iostream>
#include <unistd.h>
#include <sys/types.h>

int main(){

    fork();
    fork();
    fork();

    printf("Hello World!\n");


    // int id = fork();
    // printf("Hello! from id: %d\n", id);

    return 0;
}