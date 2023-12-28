// divider.c
#include <stdio.h>

int main()
{
    int num1, num2;
    float result;

    while (1)
    {
        printf("Enter two numbers for division: ");
        scanf("%d %d", &num1, &num2);

        if (num2 != 0)
        {
            result = (float)num1 / num2;
            printf("Result of division: %.2f\n", result);
        }
        else
        {
            printf("Error: Division by zero.\n");
        }
    }

    return 0;
}
