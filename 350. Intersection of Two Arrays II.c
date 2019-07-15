//�鲢���򣬸��Ӷ�O(nlog2n)
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
    else
    {
        tempArr[0] = sourceArr[0]; 
    }
}

void Swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int Partition(int A[], int left, int right)  // ���ֺ���
{
    int pivot = A[right];               // ����ÿ�ζ�ѡ�����һ��Ԫ����Ϊ��׼
    int tail = left - 1;                // tailΪС�ڻ�׼�����������һ��Ԫ�ص�����
    for (int i = left; i < right; i++)  // ������׼���������Ԫ��
    {
        if (A[i] <= pivot)              // ��С�ڵ��ڻ�׼��Ԫ�طŵ�ǰһ��������ĩβ
        {
            Swap(A, ++tail, i);
        }
    }
    Swap(A, tail + 1, right);           // ���ѻ�׼�ŵ�ǰһ��������ĺ�ߣ�ʣ�µ���������Ǵ��ڻ�׼��������
                                        // �ò������п��ܰѺ���Ԫ�ص��ȶ��Դ��ң����Կ��������ǲ��ȶ��������㷨
    return tail + 1;                    // ���ػ�׼������
}

void QuickSort(int A[], int left, int right)
{
    if (left >= right)
        return;
    int pivot_index = Partition(A, left, right); // ��׼������
    QuickSort(A, left, pivot_index - 1);
    QuickSort(A, pivot_index + 1, right);
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
// int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
//     int * short_nums, * long_nums;
//     int short_size, long_size;
//     if (nums1Size <= nums2Size)
//     {
//         short_nums = nums1;
//         long_nums = nums2;
//         short_size = nums1Size;
//         long_size = nums2Size;
//     }
//     else
//     {
//         short_nums = nums2;
//         long_nums = nums1;
//         short_size = nums2Size;
//         long_size = nums1Size;
//     }
    
//     int *output_arr = malloc(short_size * sizeof(int));
    
//     //��������
//     int *tmp = malloc(short_size * sizeof(int));
//     MergeSort(short_nums, tmp, 0, short_size - 1);
//     short_nums = tmp;
    
//     int *tmp_2 = malloc(long_size * sizeof(int));
//     MergeSort(long_nums, tmp_2, 0, long_size - 1);
//     long_nums = tmp_2;
    
//     *returnSize = 0;
//     int *short_nums_end = short_nums + short_size;
//     for (int i = 0; i < long_size; i++)
//     {
//         for (int *j = short_nums; j < short_nums_end; j++)
//         {
//             if (j == short_nums && long_nums[i] < *short_nums)
//             {
//                 break;
//             }
//             else if (long_nums[i] == *j)
//             {
//                 output_arr[(*returnSize)++] = long_nums[i];
//                 short_nums++;
//                 break;
//             }
//             short_nums++;
//             if (short_nums == short_nums_end)
//             {
//                 goto exit;
//             }
            
//         }
//     }
    
// exit:
//     free(tmp);
//     free(tmp_2);
//     return output_arr;
// }

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    /* �������� */
    QuickSort(nums1, 0, nums1Size - 1);
    QuickSort(nums2, 0, nums2Size - 1);
        
    int len = nums1Size < nums2Size ? nums1Size : nums2Size;
    int *output_arr = malloc((nums1Size < nums2Size ? nums1Size : nums2Size) * sizeof(int));
    
    int p = 0, k = 0;
    for (int i = 0; i < nums1Size; i++)
    {
        for (int j = p; j < nums2Size; j++)
        {
            if(nums1[i] == nums2[j])
            {
                output_arr[k++] = nums2[j];
                p = j + 1;
                break;
            }
        }
    }
    
    *returnSize = k;
    return output_arr;
}

