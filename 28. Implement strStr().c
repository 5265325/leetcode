//KMP∆•≈‰À„∑®
void fillNext(char* p, int* next)
{
    if(!p) return;
     
    int len = strlen(p);
     
    int i = 1;
    int j = 0;
     
    for(int i = 0; i < len; ++i) next[i] = 0;
     
    while(i < len-1)
    {
        if(p[i] == p[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
        {
            if(j == 0)
            {  
                i++;
                next[i] = 0;
            }
            else j = next[j];
        }
    }
} 

int strStr(char* haystack, char* needle) {
    if(!haystack || !needle) return -1;
   
    int len_h = strlen(haystack);
    int len_n = strlen(needle);
 
    if(len_n > len_h) return -1;
     
    if(len_n == 0) return 0;
 
    int* next = malloc(sizeof(int)*len_n);
    fillNext(needle, next);
     
    int i = 0;
    int j = 0;
     
    while(i < len_h)
    {
        if(haystack[i] == needle[j])
        {
            j++;
            i++;
            if(j == len_n)break;
        }
        else
        {
            if(j == 0)i++;
            else j = next[j];
        }
    }
     
    free(next);
 
    if(j == len_n)
    {   
        return i - len_n;
    }
     
    return -1; 
}