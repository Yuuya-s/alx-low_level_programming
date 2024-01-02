#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * generate_password - Generates a random password for 101-crackme.
 * 
 * Return: A pointer to the generated password.
 */
char *generate_password(void)
{
    static char password[7]; // Assuming a 6-character password plus null terminator
    
    srand(time(NULL));

    for (int i = 0; i < 6; ++i) {
        password[i] = rand() % 94 + 33; // ASCII characters between '!' (33) and '~' (126)
    }

    password[6] = '\0'; // Null-terminate the password

    return password;
}

int main(void)
{
    char *password = generate_password();

    printf("Generated Password: %s\n", password);

    return 0;
}
