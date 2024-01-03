#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

//---------------------------------------------------------------------------------------------
// Define a mutex lock for thread synchronization
pthread_mutex_t lock;

/**
 * @brief Starts the calculation process for a worker.
 *
 * This function reads a message from a worker pipe and performs actions based on the message.
 * If the message is -55555, the function returns. Otherwise, it increments the count of messages,
 * prints the message, and locks the mutex if it is the first message. If it is the second message,
 * it prints the message. If it is the third message, it prints the message, resets the count of messages,
 * and unlocks the mutex.
 *
 * @param workerName The name of the worker.
 * @param worker_pipe The pipe for communication with the worker.
 * @param countOfMessages Pointer to the count of messages received.
 */
void startCalculation(const char *workerName, const int worker_pipe, int *countOfMessages)
{
    int message = -55555;

    // Read message from worker pipe
    read(worker_pipe, &message, sizeof(message));

    // Increment count of messages
    if (message == -55555)
    {
        // If message is -55555, that means message is empty
        return;
    }
    else
    {
        (*countOfMessages)++;

        if (*countOfMessages == 1)
        {
            // Print worker name
            printf("[%s]\n", workerName);

            // Print message
            printf("%d\n", message);

            // Lock the mutex to prevent other threads from accessing shared resources
            pthread_mutex_lock(&lock);
        }
        else if (*countOfMessages == 2)
        {
            // Print message
            printf("%d\n", message);
        }
        else if (*countOfMessages == 3)
        {
            // Print message
            printf("=%d\n", message);

            // Print separator line
            printf("-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n");

            // Reset count of messages
            *countOfMessages = 0;

            // Unlock the mutex to allow other threads to access shared resources
            pthread_mutex_unlock(&lock);
        }
    }
}

//---------------------------------------------------------------------------------------------
/**
 * @brief Worker thread function that reads messages from a named pipe and performs calculations.
 *
 * @param arg The name of the named pipe to read from.
 * @return void* Returns NULL when the thread exits.
 */
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

//---------------------------------------------------------------------------------------------
/**
 * @brief Main function that monitors workers on named pipes.
 *
 * This function initializes a mutex, creates threads for each worker,
 * waits for all threads to finish, and destroys the mutex.
 *
 * @return 0 on successful execution.
 */
int main()
{
    // Print welcome message
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
