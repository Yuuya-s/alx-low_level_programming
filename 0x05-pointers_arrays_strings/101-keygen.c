#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * generate_password - Generates a random valid password.
 *
 * Return: A dynamically allocated string containing the password.
 */
char *generate_password(void)
{
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+";
    const int charset_size = sizeof(charset) - 1;

    const int min_length = 8;
    const int max_length = 12;

    int password_length = rand() % (max_length - min_length + 1) + min_length;

    char *password = (char *)malloc((password_length + 1) * sizeof(char));
    if (password == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));

    for (int i = 0; i < password_length; i++) {
        password[i] = charset[rand() % charset_size];
    }

    password[password_length] = '\0'; // Null-terminate the string

    return password;
}

int main(void)
{
    char *password = generate_password();

    printf("Generated Password: %s\n", password);

    // Don't forget to free the allocated memory
    free(password);

    return 0;
}

