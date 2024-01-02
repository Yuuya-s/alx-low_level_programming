#include <stdio.h>
#include <limits.h>

/**
 * _atoi - Converts a string to an integer.
@@ -12,45 +12,28 @@ int _atoi(char *s)
	int sign = 1;
	int i = 0;

	/* Skip leading spaces */
	/* Skip leading whitespace */
	while (s[i] == ' ')
		i++;

	/* Handle optional sign */
	/* Handle sign */
	if (s[i] == '-' || s[i] == '+') {
		sign = (s[i] == '-') ? -1 : 1;
		i++;
	}

	/* Process digits */
	while (s[i] >= '0' && s[i] <= '9') {
		/* Check for overflow */
		if (result > (2147483647 / 10) || (result == (2147483647 / 10) && s[i] - '0' > 7)) {
			return (sign == 1) ? 2147483647 : -2147483648;
		/* Check for overflow before updating result */
		if (result > INT_MAX / 10 || (result == INT_MAX / 10 && (s[i] - '0') > INT_MAX % 10)) {
			return (sign == 1) ? INT_MAX : INT_MIN;
		}

		/* Update result */
		result = result * 10 + (s[i] - '0');
		i++;
	}

	/* Apply sign to result */
	return sign * result;
}

/* Example usage */
int main(void)
{
	char str1[] = "123";
	char str2[] = "   -456";
	char str3[] = "  +789";
	char str4[] = "  2147483648";
	char str5[] = "  -2147483649";

	printf("%d\n", _atoi(str1)); /* Output: 123 */
	printf("%d\n", _atoi(str2)); /* Output: -456 */
	printf("%d\n", _atoi(str3)); /* Output: 789 */
	printf("%d\n", _atoi(str4)); /* Output: 2147483647 (overflow) */
	printf("%d\n", _atoi(str5)); /* Output: -2147483648 (overflow) */

	return (0);
	/* Apply sign to the result */
	return result * sign;
}
