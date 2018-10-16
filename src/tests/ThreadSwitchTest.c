#include "../GreenThreads.h"

#include <stdlib.h>
#include <stdio.h>

int subThreadTwo(int argc, char* argv[]){
    printf("4.       Sub thread 2 running\n");
    return 0;
}

int subThread(int argc, char* argv[]){
    printf("3.    Subthread Running\n");
    create_thread(&subThreadTwo);
    printf("5.    Running again\n");
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

    printf("6. Main done\n");
}