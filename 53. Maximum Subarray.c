int maxSubArray(int* nums, int numsSize) {
    int n, s, ans, min = 0;

    ans = s = nums[0]; //��ans��ʼ��Ϊ�����еĵĵ�һ����
    for(int i = 1; i < numsSize; i++) {
        if(s < min) min = s;
        s += nums[i];
        if(s - min > ans)
            ans = s - min;
    }
    return ans;
}