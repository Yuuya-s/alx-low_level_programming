#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all possible different combinations of three digits.
 * Numbers are separated by ", " and printed in ascending order.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int hundreds, tens, ones;

	for (hundreds = 0; hundreds <= 7; hundreds++)
	{
		for (tens = hundreds + 1; tens <= 8; tens++)
		{
			for (ones = tens + 1; ones <= 9; ones++)
			{
				putchar(hundreds % 10 + '0');
				putchar(tens % 10 + '0');
				putchar(ones % 10 + '0');

				if (hundreds != 7 || tens != 8 || ones != 9)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}

	putchar('\n');

	return (0);
}
