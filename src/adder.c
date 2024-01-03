#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Hello from adder!\n");
    printf("-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n");

    // Initialize named pipe
    if (mkfifo("adder_pipe", 0666) == -1) // returns -1 if error
    {
        perror("Error creating named pipe");
        exit(1);
    }
    else
    {
        printf("Named pipe created successfully\n");
    }

    const int adder_pipe = open("adder_pipe", O_WRONLY);

    // try catch
    if (adder_pipe == -1)
    {
        perror("Error opening named pipe");
        exit(1);
    }
    else
    {
        printf("Named pipe opened successfully\n");
    }

    while (1)
    {
        printf("Enter two numbers to add: \n");

        // Calculation Logic
        int a;
        int b;
        int result;

        scanf("%d", &a);
        write(adder_pipe, &a, sizeof(a));

        scanf("%d", &b);
        write(adder_pipe, &b, sizeof(b));

        result = a + b;
        printf("%d\n", result);
        write(adder_pipe, &result, sizeof(result));
    }

    close(adder_pipe);

    return 0;
}
