#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * generate_password - Generates a random valid password for 101-crackme.
 *
 * Return: A dynamically allocated string containing the password.
 */
char *generate_password(void)
{
    const char uppercase_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char lowercase_chars[] = "abcdefghijklmnopqrstuvwxyz";
    const char digit_chars[] = "0123456789";
    
    const int uppercase_count = sizeof(uppercase_chars) - 1;
    const int lowercase_count = sizeof(lowercase_chars) - 1;
    const int digit_count = sizeof(digit_chars) - 1;

    const int password_length = 10;

    char *password = (char *)malloc((password_length + 1) * sizeof(char));
    if (password == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));

    for (int i = 0; i < password_length; i++) {
        int category = rand() % 3;  // 0: uppercase, 1: lowercase, 2: digit

        switch (category) {
            case 0:
                password[i] = uppercase_chars[rand() % uppercase_count];
                break;
            case 1:
                password[i] = lowercase_chars[rand() % lowercase_count];
                break;
            case 2:
                password[i] = digit_chars[rand() % digit_count];
                break;
        }
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
