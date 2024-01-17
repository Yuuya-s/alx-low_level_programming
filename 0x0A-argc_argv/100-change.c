#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check for the correct number of arguments
    if (argc != 2) {
        printf("Error\n");
        return 1;
    }

    // Convert argument to integer
    int cents = atoi(argv[1]);

    // Check if the input is negative
    if (cents < 0) {
        printf("0\n");
        return 0;
    }

    // Initialize coin values
    int coins[] = {25, 10, 5, 2, 1};
    int num_coins = sizeof(coins) / sizeof(coins[0]);

    // Calculate the minimum number of coins
    int min_coins = 0;
    for (int i = 0; i < num_coins; i++) {
        min_coins += cents / coins[i];
        cents %= coins[i];
    }

    // Print the result
    printf("%d\n", min_coins);

    return 0;
}
