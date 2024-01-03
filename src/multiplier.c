#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Hello from multiplier!\n");
    printf("-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n");

    // Initialize named pipe
    mkfifo("multiplier_pipe", 0666);

    int multiplier_pipe = -1;

    multiplier_pipe = open("multiplier_pipe", O_WRONLY);

    if (multiplier_pipe == -1)
    {
        printf("Error opening pipe!\n");
        exit(1);
    }

    int test = 33;

    // write(multiplier_pipe, &test, sizeof(test));
    close(multiplier_pipe);

    while (1)
    {
        printf("Enter two numbers to multiply: \n");

        // Calculation Logic
        int a;
        int b;
        int result;

        multiplier_pipe = open("multiplier_pipe", O_WRONLY);

        if (multiplier_pipe == -1)
        {
            printf("Error opening pipe!\n");
            exit(1);
        }

        scanf("%d", &a);
        write(multiplier_pipe, &a, sizeof(a));
        close(multiplier_pipe);

        multiplier_pipe = open("multiplier_pipe", O_WRONLY);

        if (multiplier_pipe == -1)
        {
            printf("Error opening pipe!\n");
            exit(1);
        }

        scanf("%d", &b);
        write(multiplier_pipe, &b, sizeof(b));
        close(multiplier_pipe);

        multiplier_pipe = open("multiplier_pipe", O_WRONLY);

        if (multiplier_pipe == -1)
        {
            printf("Error opening pipe!\n");
            exit(1);
        }

        result = a * b;
        printf("%d\n", result);
        write(multiplier_pipe, &result, sizeof(result));
        close(multiplier_pipe);
    }

    close(multiplier_pipe);

    return 0;
}
