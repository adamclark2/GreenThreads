#include "GreenThreads.h"

#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>

/*!
Init and turn the running process into a thread
*/
void green_thread_init(void){
    jmp_buf thread_context;
    if(setjmp(thread_context) == 0){
        // Set context
        printf("Context set\n");
    }else{
        // Restored
        printf("   Restored!\n");
        exit(0);
    }

    printf("Beginning Restore:\n");
    longjmp(thread_context, 101);
}

/*!
    Create a new thread bassed of func
    It is run immediately
*/
void create_thread(thread_func* t){

}
