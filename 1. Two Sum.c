typedef struct data_t
{
    int index;
    int value;
}data_t;

void Swap(data_t * A, int i, int j)
{
    data_t temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int Partition(data_t * A, int left, int right)  // 划分函数
{
    int pivot = A[right].value;               // 这里每次都选择最后一个元素作为基准
    int tail = left - 1;                // tail为小于基准的子数组最后一个元素的索引
    for (int i = left; i < right; i++)  // 遍历基准以外的其他元素
    {
        if (A[i].value <= pivot)              // 把小于等于基准的元素放到前一个子数组末尾
        {
            Swap(A, ++tail, i);
        }
    }
    Swap(A, tail + 1, right);           // 最后把基准放到前一个子数组的后边，剩下的子数组既是大于基准的子数组
                                        // 该操作很有可能把后面元素的稳定性打乱，所以快速排序是不稳定的排序算法
    return tail + 1;                    // 返回基准的索引
}

void QuickSort(data_t * A, int left, int right)
{
    if (left >= right)
        return;
    int pivot_index = Partition(A, left, right); // 基准的索引
    QuickSort(A, left, pivot_index - 1);
    QuickSort(A, pivot_index + 1, right);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    data_t * nums_data = malloc(numsSize * sizeof(data_t));
    for (int i = 0; i < numsSize; i++)
    {
        nums_data[i].index = i;
        nums_data[i].value = nums[i];
    }
    
    QuickSort(nums_data, 0, numsSize - 1);
    
    // for (int i = 0; i < numsSize; i++)
    // {
    //     printf("%d,%d ", nums_data[i].index, nums_data[i].value);
    // }
    // printf("\n");
    
    int start = 0, end = numsSize - 1;
    int * output = malloc(2 * sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        int value = nums_data[start].value + nums_data[end].value;
        // printf("start %d, end %d, value %d\n", start, end, value);
        if (value < target)
        {
            start++;
        }
        else if (value > target)
        {
            end--;
        }
        else
        {
            output[0] = nums_data[start].index;
            output[1] = nums_data[end].index;
            break;
        }
    }
    free(nums_data);
    return output;
}