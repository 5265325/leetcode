void Swap(char A[], int i, int j)
{
    char temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int Partition(char A[], int left, int right)  // ���ֺ���
{
    char pivot = A[right];               // ����ÿ�ζ�ѡ�����һ��Ԫ����Ϊ��׼
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

void QuickSort(char A[], int left, int right)
{
    if (left >= right)
        return;
    int pivot_index = Partition(A, left, right); // ��׼������
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