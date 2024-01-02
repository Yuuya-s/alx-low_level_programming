#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generates random valid passwords for 101-crackme.
 * Return: 0 on success.
 */
int main(void)
{
    srand(time(NULL));  // Seed for random number generation based on current time

    // Define the character set for the password
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int password_length = 12;  // Adjust the length as needed

    printf("Generated Password: ");

    // Generate random password
    for (int i = 0; i < password_length; ++i) {
        // Generate a random index within the character set
        int random_index = rand() % (sizeof(charset) - 1);
        // Print the character at the random index
        printf("%c", charset[random_index]);
    }

    printf("\n");

    return 0;
}
