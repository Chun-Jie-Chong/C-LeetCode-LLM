#include <limits.h>

int jump(int* nums, int numsSize) {
    if (numsSize <= 1) return 0;
    
    int jumps = 0, curr_end = 0, farthest = 0;
    
    for (int i = 0; i < numsSize - 1; i++) {
        farthest = (farthest > i + nums[i]) ? farthest : i + nums[i];
        if (i == curr_end) {
            jumps++;
            curr_end = farthest;
            if (curr_end >= numsSize - 1) break;
        }
    }
    
    return jumps;
}
