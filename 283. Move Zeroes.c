void moveZeroes(int* nums, int numsSize) {
    int end = 0;
    for (register int i = 0; i < numsSize; i++)
    {
        if (nums[i] != 0)
        {
            nums[end++] = nums[i];
        }
    }
    while(end < numsSize)
    {
        nums[end++] = 0;
    }
}