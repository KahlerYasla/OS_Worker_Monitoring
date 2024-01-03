/**
 * @file adder.c
 * @brief This file contains the implementation of the adder program.
 * The adder program reads two numbers from the user, adds them, and writes the result to a named pipe.
 * It also initializes the named pipe and handles error conditions.
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Print a greeting message
    printf("Hello from adder!\n");
    printf("-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n");

    // Create the named pipe
    mkfifo("adder_pipe", 0666);

    int adder_pipe = -1;

    // Open the named pipe for writing
    adder_pipe = open("adder_pipe", O_WRONLY);

    if (adder_pipe == -1)
    {
        printf("Error opening pipe!\n");
        exit(1);
    }

    int test = 33;

    // Write the test value to the named pipe
    write(adder_pipe, &test, sizeof(test));
    close(adder_pipe);

    while (1)
    {
        printf("Enter two numbers to add: \n");

        // Calculation Logic
        int a;
        int b;
        int result;

        // Open the named pipe for writing
        adder_pipe = open("adder_pipe", O_WRONLY);

        if (adder_pipe == -1)
        {
            printf("Error opening pipe!\n");
            exit(1);
        }

        // Read the first number from the user and write it to the named pipe
        scanf("%d", &a);
        write(adder_pipe, &a, sizeof(a));
        close(adder_pipe);

        // Open the named pipe for writing
        adder_pipe = open("adder_pipe", O_WRONLY);

        if (adder_pipe == -1)
        {
            printf("Error opening pipe!\n");
            exit(1);
        }

        // Read the second number from the user and write it to the named pipe
        scanf("%d", &b);
        write(adder_pipe, &b, sizeof(b));
        close(adder_pipe);

        // Open the named pipe for writing
        adder_pipe = open("adder_pipe", O_WRONLY);

        if (adder_pipe == -1)
        {
            printf("Error opening pipe!\n");
            exit(1);
        }

        // Calculate the sum of the two numbers
        result = a + b;
        printf("%d\n", result);
        write(adder_pipe, &result, sizeof(result));
        close(adder_pipe);
    }

    return 0;
}
