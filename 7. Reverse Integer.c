int reverse(int x) {
    int64_t res = 0;
    while(x) {
        res = res * 10 + x % 10;
        if(res < INT_MIN  || res > INT_MAX) {
            return 0;
        }
        x /= 10;
    }
    return (int)res;
    
    // int newx = 0;
    // while (x!=0){
    //     if(newx<-214748364||newx>214748364) return 0;
    //     newx = newx*10+x%10;x/=10;
    // }
    // return newx;
}