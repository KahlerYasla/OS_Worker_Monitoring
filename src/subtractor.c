#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Hello from subtractor!\n");
    printf("-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n");

    // Initialize named pipe
    mkfifo("subtractor_pipe", 0666);

    int subtractor_pipe = -1;

    subtractor_pipe = open("subtractor_pipe", O_WRONLY);

    if (subtractor_pipe == -1)
    {
        printf("Error opening pipe!\n");
        exit(1);
    }

    int test = 33;

    write(subtractor_pipe, &test, sizeof(test));
    close(subtractor_pipe);

    while (1)
    {
        printf("Enter two numbers to substract: \n");

        // Calculation Logic
        int a;
        int b;
        int result;

        subtractor_pipe = open("subtractor_pipe", O_WRONLY);

        if (subtractor_pipe == -1)
        {
            printf("Error opening pipe!\n");
            exit(1);
        }

        scanf("%d", &a);
        write(subtractor_pipe, &a, sizeof(a));
        close(subtractor_pipe);

        subtractor_pipe = open("subtractor_pipe", O_WRONLY);

        if (subtractor_pipe == -1)
        {
            printf("Error opening pipe!\n");
            exit(1);
        }

        scanf("%d", &b);
        write(subtractor_pipe, &b, sizeof(b));
        close(subtractor_pipe);

        subtractor_pipe = open("subtractor_pipe", O_WRONLY);

        if (subtractor_pipe == -1)
        {
            printf("Error opening pipe!\n");
            exit(1);
        }

        result = a - b;
        printf("%d\n", result);
        write(subtractor_pipe, &result, sizeof(result));
        close(subtractor_pipe);
    }

    close(subtractor_pipe);

    return 0;
}
