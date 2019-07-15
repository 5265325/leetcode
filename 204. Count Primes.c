int countPrimes(int n) {
    if (n == 0 || n == 1) {
        return 0;
    }
    
    //埃拉托斯特尼筛法
    bool *pb = calloc(n-1,sizeof(bool));

    int ret_c=0;
    // idx 0 represent 2
    int idx=0;
    int pend=n-2;
    while(idx<pend){
        if(0==pb[idx]){
            ++ret_c;
            int op=idx;
            while(op<pend){
                pb[op]=1;
                op+=(idx+2);
            }
        } 
        ++idx;
    }
    free(pb);
    return ret_c;
}