#include <stdbool.h>

bool mergeTriplets(int** triplets, int tripletsSize, int* target, int targetSize) {
    bool foundA = false, foundB = false, foundC = false;
    
    for (int i = 0; i < tripletsSize; i++) {
        if (triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2])
            continue;
        
        if (triplets[i][0] == target[0])
            foundA = true;
        if (triplets[i][1] == target[1])
            foundB = true;
        if (triplets[i][2] == target[2])
            foundC = true;

        if (foundA && foundB && foundC)
            return true;
    }
    
    return false;
}
