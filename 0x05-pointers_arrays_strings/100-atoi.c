#include <stdio.h>
#include <limits.h>

/**
 * _atoi - Converts a string to an integer.
 * @s: The input string.
 *
 * Return: The converted integer.
 */
int _atoi(char *s)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	/* Skip leading whitespace */
	while (s[i] == ' ')
		i++;

	/* Handle sign */
	if (s[i] == '-' || s[i] == '+') {
		sign = (s[i] == '-') ? -1 : 1;
		i++;
	}

	/* Process digits */
	while (s[i] >= '0' && s[i] <= '9') {
		/* Check for overflow before updating result */
		if (result > INT_MAX / 10 || (result == INT_MAX / 10 && (s[i] - '0') > INT_MAX % 10)) {
			return (sign == 1) ? INT_MAX : INT_MIN;
		}

		/* Update result */
		result = result * 10 + (s[i] - '0');
		i++;
	}

	/* Apply sign to the result */
	return result * sign;
}
