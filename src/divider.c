#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Hello from divider!\n");
    printf("-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n");

    // Create the pipe
    mkfifo("divider_pipe", 0666);

    int divider_pipe = -1;

    divider_pipe = open("divider_pipe", O_WRONLY);

    if (divider_pipe == -1)
    {
        printf("Error opening pipe!\n");
        exit(1);
    }

    int test = 33;

    write(divider_pipe, &test, sizeof(test));
    close(divider_pipe);

    while (1)
    {
        printf("Enter two numbers to divide: \n");

        // Calculation Logic
        int a;
        int b;
        int result;

        divider_pipe = open("divider_pipe", O_WRONLY);

        if (divider_pipe == -1)
        {
            printf("Error opening pipe!\n");
            exit(1);
        }

        scanf("%d", &a);
        write(divider_pipe, &a, sizeof(a));
        close(divider_pipe);

        divider_pipe = open("divider_pipe", O_WRONLY);

        if (divider_pipe == -1)
        {
            printf("Error opening pipe!\n");
            exit(1);
        }

        scanf("%d", &b);
        write(divider_pipe, &b, sizeof(b));
        close(divider_pipe);

        divider_pipe = open("divider_pipe", O_WRONLY);

        if (divider_pipe == -1)
        {
            printf("Error opening pipe!\n");
            exit(1);
        }

        result = a / b;
        printf("%d\n", result);
        write(divider_pipe, &result, sizeof(result));
        close(divider_pipe);
    }

    close(divider_pipe);

    return 0;
}
