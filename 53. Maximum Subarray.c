int maxSubArray(int* nums, int numsSize) {
    int n, s, ans, min = 0;

    ans = s = nums[0]; //把ans初始化为序列中的的第一个数
    for(int i = 1; i < numsSize; i++) {
        if(s < min) min = s;
        s += nums[i];
        if(s - min > ans)
            ans = s - min;
    }
    return ans;
}