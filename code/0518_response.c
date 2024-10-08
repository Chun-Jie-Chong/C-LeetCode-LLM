int change(int amount, int* coins, int coinsSize) {
    int dp[amount + 1];
    for (int i = 0; i <= amount; i++) {
        dp[i] = 0;
    }
    dp[0] = 1;
    for (int i = 0; i < coinsSize; i++) {
        for (int j = coins[i]; j <= amount; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }
    return dp[amount];
}
