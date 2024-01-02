#include <stdio.h>

/**
 * _atoi - Converts a string to an integer.
 * @s: The input string.
 *
 * Return: The converted integer.
 */
int _atoi(char *s)
{
	int result = 0;
	int sign = 1; /* 1 for positive, -1 for negative */
	int i = 0;

	/* Skip leading whitespaces */
	while (s[i] == ' ')
		i++;

	/* Handle the sign */
	if (s[i] == '-' || s[i] == '+') {
		sign = (s[i] == '-') ? -1 : 1;
		i++;
	}

	/* Process the digits */
	while (s[i] >= '0' && s[i] <= '9') {
		/* Check for overflow before updating the result */
		if (result > (2147483647 - (s[i] - '0')) / 10) {
			/* Overflow, return maximum or minimum integer value */
			return (sign == 1) ? 2147483647 : -2147483648;
		}

		result = result * 10 + (s[i] - '0');
		i++;
	}

	return result * sign;
}

int main(void)
{
	char str[] = "-12345";
	int result = _atoi(str);
	printf("Converted integer: %d\n", result);

	return 0;
}
