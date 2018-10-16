// Run 'interrupt 100 times a sec'
#define GREEN_THREAD_TIMER_FREQ 100
#include <setjmp.h>


typedef int thread_func(int argc, char* argv[]);

struct gtThread{
    int tid;
    char name[16];
    jmp_buf thread_context;
};

/*!
Init and turn the running process into a thread
*/
void green_thread_init(void);

/*!
    Create a new thread bassed of func
    It is run whenever
*/
void create_thread(thread_func* t);

static void gt_context_switch(struct gtThread* next);
