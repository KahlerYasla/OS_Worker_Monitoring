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

    // Initialize named pipe
    mkfifo("divider_pipe", 0666);

    const int divider_pipe = open("divider_pipe", O_WRONLY);

    while (1)
    {
        printf("Enter two numbers to divide: \n");

        // Calculation Logic
        int a;
        int b;
        int result;

        scanf("%d", &a);
        write(divider_pipe, &a, sizeof(a));

        scanf("%d", &b);
        write(divider_pipe, &b, sizeof(b));

        result = a / b;
        printf("%d\n", result);
        write(divider_pipe, &result, sizeof(result));
    }

    close(divider_pipe);

    return 0;
}
