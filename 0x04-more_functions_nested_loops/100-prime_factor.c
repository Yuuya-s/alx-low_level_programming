#include <stdio.h>

/**
 * largest_prime_factor - finds the largest prime factor of a number.
 * @n: The number to find the largest prime factor for.
 * Return: The largest prime factor.
 */
long largest_prime_factor(long n)
{
    long i;

    for (i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            if (n == i)
                return i;
            n /= i;
        }
    }

    return n; // This handles the case when the remaining value is a prime number
}

int main(void)
{
    long number = 612852475143;
    long result;

    result = largest_prime_factor(number);

    printf("%ld\n", result);

    return 0;
}
