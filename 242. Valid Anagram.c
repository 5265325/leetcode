void Swap(char A[], int i, int j)
{
    char temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int Partition(char A[], int left, int right)  // 划分函数
{
    char pivot = A[right];               // 这里每次都选择最后一个元素作为基准
    int tail = left - 1;                // tail为小于基准的子数组最后一个元素的索引
    for (int i = left; i < right; i++)  // 遍历基准以外的其他元素
    {
        if (A[i] <= pivot)              // 把小于等于基准的元素放到前一个子数组末尾
        {
            Swap(A, ++tail, i);
        }
    }
    Swap(A, tail + 1, right);           // 最后把基准放到前一个子数组的后边，剩下的子数组既是大于基准的子数组
                                        // 该操作很有可能把后面元素的稳定性打乱，所以快速排序是不稳定的排序算法
    return tail + 1;                    // 返回基准的索引
}

void QuickSort(char A[], int left, int right)
{
    if (left >= right)
        return;
    int pivot_index = Partition(A, left, right); // 基准的索引
    QuickSort(A, left, pivot_index - 1);
    QuickSort(A, pivot_index + 1, right);
}

// bool isAnagram(char* s, char* t) {
//     int len_s = strlen(s);
//     int len_t = strlen(t);
    
//     if (len_s != len_t) {
//         return false;
//     }
    
//     QuickSort(s, 0, len_s - 1);
//     QuickSort(t, 0, len_t - 1);
    
//     return strcmp(s, t) == 0;
// }

bool isAnagram(char* s, char* t) {
    int a[26]={0};
    int b[26]={0};
    
    int i;
    int t1,t2;
    for(i=0;s[i]!='\0';i++)
    {
        if(t[i]=='\0')
            return false;
        
        t1=s[i]-'a';
        t2=t[i]-'a';
        
        a[t1]++;
        b[t2]++;
    }
    if(t[i]!='\0')
        return false;
    
    for(i=0;i<26;i++)
    {
        if(a[i]!=b[i])
            return false;
    }
    return true;
}