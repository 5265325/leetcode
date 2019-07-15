bool isPowerOfThree(int n) {
    if (n == 1) {
        return true;
    }
    if (n <= 0 || n % 3 > 0) {
        return false;
    }
    const int maxint=0x7fffffff;
    
    // int k=log(maxint)/log(3);
    // int b3=pow(3,k);
    
    int b3 = 1162261467;
    
    return (b3%n==0);
}