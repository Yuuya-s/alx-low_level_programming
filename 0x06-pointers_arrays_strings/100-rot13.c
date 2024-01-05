#include <stdio.h>

/**
 * rot13 - Encode a string using rot13.
 * @str: The input string to be encoded.
 *
 * Return: A pointer to the encoded string.
 */
char *rot13(char *str) {
    if (str == NULL)
        return NULL;

    for (; *str; ++str) {
        if ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z')) {
            if ((*str >= 'A' && *str <= 'M') || (*str >= 'a' && *str <= 'm'))
                *str += 13;
            else
                *str -= 13;
        }
    }

    return str;
}

int main() {
    char input[] = "Hello, World!";
    printf("Original: %s\n", input);

    rot13(input);

    printf("Encoded: %s\n", input);

    return 0;
}

