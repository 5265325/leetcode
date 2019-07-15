int max(int a, int b)
{
    return a > b ? a : b;
}

int rob(int* nums, int numsSize) {
    if (numsSize == 0)
        return 0;
    if (numsSize == 1)
        return nums[0];
    if (numsSize == 2)
    {
        if (nums[0] > nums[1])
            return nums[0];
        else
            return nums[1];
    }
    int first = 0;  //����rob(n-2)��Ч��
    int second = 0;   //����rob(n-1)��Ч��
    int tmp = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (first + nums[i] > second)
        {
            tmp = second;
            second = first + nums[i];
            first = max(first, tmp);
        }
        else
        {
            first = second;
        }
    }
    return max(first, second);
}