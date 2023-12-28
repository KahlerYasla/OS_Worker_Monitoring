// worker_monitor.c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *worker_thread(void *arg)
{
    int worker_id = *((int *)arg);

    while (1)
    {
        pthread_mutex_lock(&lock);
        printf("Worker %d is in the critical section.\n", worker_id);
        // Perform worker-specific operations here
        pthread_mutex_unlock(&lock);

        // Simulate some work
        sleep(2);
    }

    return NULL;
}

int main()
{
    pthread_t worker_threads[4];
    int thread_ids[4] = {1, 2, 3, 4};

    // Create worker threads
    for (int i = 0; i < 4; ++i)
    {
        pthread_create(&worker_threads[i], NULL, worker_thread, &thread_ids[i]);
    }

    // Join worker threads
    for (int i = 0; i < 4; ++i)
    {
        pthread_join(worker_threads[i], NULL);
    }

    return 0;
}
