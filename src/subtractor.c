#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Hello from substractor!\n");
    printf("-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n");

    // Initialize named pipe
    mkfifo("subtractor_pipe", 0666);

    const int subtractor_pipe = open("subtractor_pipe", O_WRONLY);

    while (1)
    {
        printf("Enter two numbers to add: \n");

        // Calculation Logic
        int a;
        int b;
        int result;

        scanf("%d", &a);
        write(subtractor_pipe, &a, sizeof(a));

        scanf("%d", &b);
        write(subtractor_pipe, &b, sizeof(b));

        result = a - b;
        printf("%d\n", result);
        write(subtractor_pipe, &result, sizeof(result));
    }

    close(subtractor_pipe);

    return 0;
}
