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

    const int multiplier_pipe = open("multiplier_pipe", O_WRONLY);

    while (1)
    {
        printf("Enter two numbers to add: \n");

        // Calculation Logic
        int a;
        int b;
        int result;

        scanf("%d", &a);
        write(multiplier_pipe, &a, sizeof(a));

        scanf("%d", &b);
        write(multiplier_pipe, &b, sizeof(b));

        result = a * b;
        printf("%d\n", result);
        write(multiplier_pipe, &result, sizeof(result));
    }

    close(multiplier_pipe);

    return 0;
}
