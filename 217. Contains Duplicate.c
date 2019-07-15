//解法1，先排序后对比，复杂度取决于排序算法，这里使用归并排序，复杂度O(nlog2n)
void Merge(int sourceArr[],int tempArr[], int startIndex, int midIndex, int endIndex)
{
    int i = startIndex, j=midIndex+1, k = startIndex;
    while(i!=midIndex+1 && j!=endIndex+1)
    {
        if(sourceArr[i] > sourceArr[j])
            tempArr[k++] = sourceArr[j++];
        else
            tempArr[k++] = sourceArr[i++];
    }
    while(i != midIndex+1)
        tempArr[k++] = sourceArr[i++];
    while(j != endIndex+1)
        tempArr[k++] = sourceArr[j++];
    for(i=startIndex; i<=endIndex; i++)
        sourceArr[i] = tempArr[i];
}
 
//内部使用递归
void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex)
{
    int midIndex;
    if(startIndex < endIndex)
    {
        midIndex = startIndex + (endIndex-startIndex) / 2;//避免溢出int
        MergeSort(sourceArr, tempArr, startIndex, midIndex);
        MergeSort(sourceArr, tempArr, midIndex+1, endIndex);
        Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
    }
}

bool containsDuplicate(int* nums, int numsSize) {
    if (numsSize <= 0)
    {
        return false;
    }
    
    int * tmp = malloc(numsSize * sizeof(int));
    MergeSort(nums, tmp, 0, numsSize - 1);
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] == nums[i - 1])
        {
            free(tmp);
            return true;
        }
    }
    free(tmp);
    return false;
}

//解法2，遍历所有值的同时遍对比前n-1项，复杂度(n^2)
// bool containsDuplicate(int* nums, int numsSize) {
//     if (numsSize <= 1)
//     {
//         return false;
//     }
    
//     for (int i = 1; i < numsSize; i++)
//     {
//         for (int j = 0; j < i; j++)
//         {
//             if (nums[i] == nums[j])
//             {
//                 return true;
//             }
//         }
//     }
//     return false;
// }
