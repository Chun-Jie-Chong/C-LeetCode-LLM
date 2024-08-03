void moveZeroes(int* nums, int numsSize) {
    int insert_pos = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[insert_pos++] = nums[i];
        }
    }
    for (int i = insert_pos; i < numsSize; i++) {
        nums[i] = 0;
    }
}
