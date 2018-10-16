#include "../GreenThreads.h"

#include <stdlib.h>
#include <stdio.h>

int subThreadThree(int argc, char* argv[]){
    printf("5.          Sub thread 3 running\n");
    return 0;
}

int subThreadTwo(int argc, char* argv[]){
    printf("4.       Subthread 2 Running\n");
    create_thread(&subThreadThree);
    printf("6.       Running 2 again\n");
    return 0;
}

int subThread(int argc, char* argv[]){
    printf("3.    Subthread 1 Running\n");
    create_thread(&subThreadTwo);
    printf("7.    Running 1 again\n");
    return 0;
}

/*!
    Should do
    1.
    2.
    3.
    4.
    5.
    6.

    In order
*/
int main(int argc, char* argv[]){
    printf("1. Init:\n");
    green_thread_init();

    printf("2. Create\n");
    create_thread(&subThread);

    printf("8. Main done\n");
}