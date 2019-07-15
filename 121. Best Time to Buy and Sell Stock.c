int maxProfit(int* prices, int pricesSize) {
    if (prices == NULL || pricesSize == 0) {
        return 0;
    }
    
    int max = 0,realmax = 0;
    for(int i = 1;i < pricesSize;i++)
    {
        max += prices[i] - prices[i-1];
        if(max < 0)
            max = 0;
        if(max > realmax)
            realmax = max;
    }
    return realmax;
}