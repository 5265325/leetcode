// void rotate(int* nums, int numsSize, int k) {
//     if (numsSize <= 1 || k == 0)
//     {
//         return;
//     }
    
//     int* tmp = (int*)malloc(sizeof(int) * numsSize);
    
//     for(int i = 0; i < numsSize; i++)
//         tmp[i] = nums[i];
    
//     for(int i = 0; i < numsSize; i++)
//         nums[(i + k) % numsSize] = tmp[i];
    
//     free(tmp);
// }

void rotate(int* nums, int numsSize, int k) {
        if(numsSize < 2 || k ==0) return;
        if(k > numsSize)
                k = k % numsSize;
        if(k == numsSize) return;

        int i = numsSize - 1;
        int h ,j = i;
        int ti = i;
        int tmp = nums[i];

        for(int cnt = 0; cnt < numsSize; cnt++){
                h = i - k;
                // printf("%d %d %d\n", j, ti, numsSize + h);
                if(h < 0) {
                        if(j == numsSize + h || ti == numsSize + h || cnt == numsSize - 1) {
                                nums[i] = tmp;
                                // printf("%d nums[%d] = %d\n", h, i, nums[i]);
                                i = --j;
                                ti = i;
                                tmp = nums[ti];
                        } else {
                                j = numsSize + h;
                                nums[i] = nums[j];
                                // printf("%d nums[%d] = nums[%d] = %d\n", h, i, j, nums[i]);
                                i = j;
                        }
                } else {
                        nums[i] = nums[h];
                        // printf("%d nums[%d] = nums[%d] = %d\n", h, i, h, nums[i]);
                        i -= k;
                }
        }
}