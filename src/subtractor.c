// subtractor.c
#include <stdio.h>

int main()
{
    int num1, num2, result;

    while (1)
    {
        printf("Enter two numbers for subtraction: ");
        scanf("%d %d", &num1, &num2);

        result = num1 - num2;

        printf("Result of subtraction: %d\n", result);
    }

    return 0;
}
