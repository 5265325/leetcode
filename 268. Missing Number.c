int missingNumber(int* nums, int numsSize) {
    // int sum = 0;
    // for (int i = 0; i < numsSize; i++) {
    //     sum += nums[i];
    // }
    // return numsSize * (numsSize + 1) / 2 - sum;
    
    if(NULL == nums || 0 == numsSize)
        return 0;
    
    /*���ܺͼ�ȥ����ĺ�*/
    int sum = 0;
    int oSum = 0;
    int i = 0;
    for(;i < numsSize;i++)
    {
        sum+=i;
        oSum+=nums[i];
    }
    return sum-oSum+i;
}