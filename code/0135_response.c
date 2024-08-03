#include <stdio.h>
#include <stdlib.h>

int candy(int* ratings, int ratingsSize) {
    // Allocate memory for the candies array
    int* candies = (int*)malloc(ratingsSize * sizeof(int));
    
    // Initialize all elements of candies array to 1 (each child gets at least one candy)
    for (int i = 0; i < ratingsSize; i++) {
        candies[i] = 1;
    }
    
    // Traverse from left to right
    for (int i = 1; i < ratingsSize; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }
    
    // Traverse from right to left
    for (int i = ratingsSize - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            if (candies[i] <= candies[i + 1]) {
                candies[i] = candies[i + 1] + 1;
            }
        }
    }
    
    // Calculate the total number of candies required
    int totalCandies = 0;
    for (int i = 0; i < ratingsSize; i++) {
        totalCandies += candies[i];
    }
    
    // Free the allocated memory
    free(candies);
    
    return totalCandies;
}
