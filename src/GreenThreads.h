// Run 'interrupt 100 times a sec'
#define GREEN_THREAD_TIMER_FREQ 100


typedef int thread_func(int argc, char* argv[]);

/*!
Init and turn the running process into a thread
*/
void green_thread_init(void);

/*!
    Create a new thread bassed of func
    It is run immediately
*/
void create_thread(thread_func* t);
