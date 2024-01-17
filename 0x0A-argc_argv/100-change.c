#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 2) {
        printf("Error\n");
        return 1;
    }

    // Convert the argument to an integer
    int cents = atoi(argv[1]);

    // Check if the input is negative
    if (cents < 0) {
        printf("0\n");
        return 0;
    }

    // Array to store the available coin values
    int coins[] = {25, 10, 5, 2, 1};
    int numCoins = sizeof(coins) / sizeof(coins[0]);

    // Calculate the minimum number of coins
    int count = 0;
    for (int i = 0; i < numCoins; i++) {
        while (cents >= coins[i]) {
            cents -= coins[i];
            count++;
        }
    }

    // Print the result
    printf("%d\n", count);

    return 0;
}
