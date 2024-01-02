/**
 * _atoi - Converts a string to an integer.
 * @s: The string to convert.
 *
 * Return: The converted integer.
 */
int _atoi(char *s)
{
	int sign = 1;
	int result = 0;
	int digit;

	if (!s)
		return 0;

	/* Handle leading signs */
	while (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}

	/* Convert string to integer */
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
		{
			digit = *s - '0';

			/* Check for overflow */
			if (result > (INT_MAX - digit) / 10)
			{
				if (sign == 1)
					return INT_MAX;
				else
					return INT_MIN;
			}

			result = result * 10 + digit;
		}
		else
		{
			/* Stop at the first non-digit character */
			break;
		}

		s++;
	}

	return result * sign;
}
