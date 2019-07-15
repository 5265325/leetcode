//�ⷨ1���������Աȣ����Ӷ�ȡ���������㷨������ʹ�ù鲢���򣬸��Ӷ�O(nlog2n)
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
 
//�ڲ�ʹ�õݹ�
void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex)
{
    int midIndex;
    if(startIndex < endIndex)
    {
        midIndex = startIndex + (endIndex-startIndex) / 2;//�������int
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

//�ⷨ2����������ֵ��ͬʱ��Ա�ǰn-1����Ӷ�(n^2)
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
