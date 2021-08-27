/* Terry Delaney
 *
 * My observations when running this program is that the majority of the time the count reaches 100, with the occasional
 * count being one short with 99, however the individual count sometimes does vary as threads are working with the
 * global variable that there are times that one thread will jump into the middle of a different thread's incrementation
 *
 * I also discovered that while my MacBook Pro would only let the final thread print to the Terminal, ALE would allow
 * for all of the threads to print to the Terminal display.
*/

#include "HW5.h"

int main() {

    // Clear the screen
    system("clear");

    // Create 10 pthreads that increment a global integer 10 times - Each pthread needs to print a statement with it's ID and the global variable's value

    // Create global variables

    counter = (int) malloc (sizeof(int));
    threadwait = (int) malloc (sizeof(int));
    counter = 0;

    // Create 10 pthreads

    threadwait = 1;

    for (int i = 0; i < 10; i++)
    {
        pthread_create(&threadid[i], NULL, threadroutine, NULL);
        printf("Thread #: %d has ID %d\n", i, (int)threadid[i]);
    }

    threadwait = 0;

    for (int k = 0; k < 10; k++)
    {
       pthread_join(threadid[k], NULL);
    }

    printf("\nThe final value of the global integer is: %d\n\n", counter);

    return 0;
}

void * threadroutine()
{
    while (threadwait != 0)
        pause();

    for (int j = 0; j < 10; j++)
    {
        printf("Thread ID: %x Global Integer Value: %d\n", pthread_self(), counter++);
    }

    pthread_exit(NULL);
}

