#include <stdbool.h>

bool mergeTriplets(int** triplets, int tripletsSize, int* tripletsColSize, int* target, int targetSize) {
    // Flags to check if we can form the target triplet
    bool foundA = false;
    bool foundB = false;
    bool foundC = false;
    
    for (int i = 0; i < tripletsSize; i++) {
        // Only consider triplets that do not exceed the target in any dimension
        if (triplets[i][0] <= target[0] && triplets[i][1] <= target[1] && triplets[i][2] <= target[2]) {
            // Check if the current triplet can contribute to the target
            if (triplets[i][0] == target[0]) {
                foundA = true;
            }
            if (triplets[i][1] == target[1]) {
                foundB = true;
            }
            if (triplets[i][2] == target[2]) {
                foundC = true;
            }
        }
    }
    
    // If all parts of the target triplet can be found, return true
    return foundA && foundB && foundC;
}