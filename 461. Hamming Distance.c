int hammingDistance(int x, int y) {
    int num=x^y;
    int count=0;
    while(num){
        count++;
        num&=num-1;
    }
    return count;
}