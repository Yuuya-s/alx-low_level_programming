#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all possible different combinations of two digits.
 * Numbers are separated by ", " and printed in ascending order.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int tens, ones;

    for (tens = 0; tens <= 8; tens++)
    {
        for (ones = tens + 1; ones <= 9; ones++)
        {
            putchar(tens % 10 + '0');
            putchar(ones % 10 + '0');

            if (tens != 8 || ones != 9)
            {
                putchar(',');
                putchar(' ');
            }
        }
    }

    putchar('\n');

    return (0);
}
