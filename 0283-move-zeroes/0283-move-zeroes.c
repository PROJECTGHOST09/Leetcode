void moveZeroes(int* nums, int numsSize) {
    int k = 0; // Pointer for where the next non-zero number goes

    // Step 1: Push all non-zero numbers to the front
    // (This is the exact same logic as removeElement where val = 0)
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[k] = nums[i];
            k++;
        }
    }
    
    // Step 2: Fill the remaining slots with 0
    // We start from 'k' because that is exactly where the non-zero numbers ended
    for (int i = k; i < numsSize; i++) {
        nums[i] = 0;
    }
}