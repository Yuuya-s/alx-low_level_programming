#include <stdio.h>

int minCoins(int coins[], int n, int amount) {
    int table[amount + 1];

    table[0] = 0;

    for (int i = 1; i <= amount; i++)
        table[i] = INT_MAX;

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) {
                int subResult = table[i - coins[j]];
                if (subResult != INT_MAX && subResult + 1 < table[i])
                    table[i] = subResult + 1;
            }
        }
    }

    return table[amount];
}

int main() {
    int coins[] = {1, 5, 10, 25}; // Example coin denominations (in cents)
    int n = sizeof(coins) / sizeof(coins[0]);
    int amount;

    printf("Enter the amount in cents: ");
    scanf("%d", &amount);

    int result = minCoins(coins, n, amount);

    printf("Minimum number of coins needed: %d\n", result);

    return 0;
}
