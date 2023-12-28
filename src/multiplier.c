// multiplier.c
#include <stdio.h>

int main()
{
    int num1, num2, result;

    while (1)
    {
        printf("Enter two numbers for multiplication: ");
        scanf("%d %d", &num1, &num2);

        result = num1 * num2;

        printf("Result of multiplication: %d\n", result);
    }

    return 0;
}
