uint32_t reverseBits(uint32_t n) {
    if (n == 0) {
        return 0;
    }
    uint32_t ret=0;
    int count=0;
    while(n){
        ret=(ret<<1)|(n&1);
        n>>=1;
        count++;
    }
    if(count<32){
        ret<<=32-count;
    }
    return ret;
}