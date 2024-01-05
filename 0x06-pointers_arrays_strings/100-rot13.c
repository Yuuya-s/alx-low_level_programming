#include <stdio.h>

/*
 * rot13 - Encodes a string using the ROT13 cipher.
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

