#include <stdio.h>
#include <string.h>

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0) return 0;
    
    int hold = -prices[0]; // Max profit when holding a stock
    int sold = 0;          // Max profit when sold a stock
    int rest = 0;          // Max profit when in cooldown period (rest)
    
    for (int i = 1; i < pricesSize; i++) {
        int prev_hold = hold;
        hold = ((rest - prices[i]) > hold) ? (rest - prices[i]) : hold;
        rest = (sold > rest) ? sold : rest;
        sold = prev_hold + prices[i];
    }
    
    return (sold > rest) ? sold : rest;
}
