#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0) return 0;
    
    int sell = 0, prev_sell = 0;
    int buy = -prices[0], prev_buy;
    
    for (int i = 1; i < pricesSize; i++) {
        prev_buy = buy;
        buy = (prev_sell - prices[i] > buy) ? 
              prev_sell - prices[i] : buy;
        prev_sell = sell;
        sell = (prev_buy + prices[i] > sell) ? 
               prev_buy + prices[i] : sell;
    }
    
    return sell;
}
