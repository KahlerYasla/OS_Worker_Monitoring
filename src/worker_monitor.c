#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

pthread_mutex_t lock;

void startCalculation(const char *workerName, const int worker_pipe, int *countOfMessages)
{
    int message = -1;
    read(worker_pipe, &message, sizeof(message));

    // Increment count of messages
    if (message != -1)
    {
        (*countOfMessages)++;
    }

    if (*countOfMessages == 1)
    {
        printf("[%s]\n", workerName);
        printf("1: %d ", message);

        // Dont allow other threads focus.
        pthread_mutex_lock(&lock);
    }
    else if (*countOfMessages == 2)
    {
        printf("2: %d ", message);
    }
    else if (*countOfMessages == 3)
    {
        printf("Result: %d\n", message);
        printf("-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n");

        *countOfMessages = 0;

        // Unfocus on this thread
        pthread_mutex_unlock(&lock);
    }
}

void *workerThread(void *arg)
{
    const char *workerName = (const char *)arg;

    // Open the relevant named pipe for reading
    const int worker_pipe = open(workerName, O_RDONLY);

    int countOfMessages = 0;

    while (1)
    {
        // Start calculation
        startCalculation(workerName, worker_pipe, &countOfMessages);
    }

    // Close the named pipe
    close(worker_pipe);

    pthread_exit(NULL);
}

int main()
{
    printf("Hello from worker monitor!\n");
    printf("Monitoring workers on named pipes...\n");
    printf("-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n");

    // Initialize mutex
    pthread_mutex_init(&lock, NULL);

    // Create threads for each worker
    pthread_t adder_thread, divider_thread, multiplier_thread, subtractor_thread;

    pthread_create(&adder_thread, NULL, workerThread, "adder_pipe");
    pthread_create(&divider_thread, NULL, workerThread, "divider_pipe");
    pthread_create(&multiplier_thread, NULL, workerThread, "multiplier_pipe");
    pthread_create(&subtractor_thread, NULL, workerThread, "subtractor_pipe");

    // Wait for all threads to finish
    pthread_join(adder_thread, NULL);
    pthread_join(divider_thread, NULL);
    pthread_join(multiplier_thread, NULL);
    pthread_join(subtractor_thread, NULL);

    // Destroy the mutex
    pthread_mutex_destroy(&lock);

    return 0;
}
