int maxProfit(int* prices, int pricesSize) {
    if (pricesSize <= 0)
    {
        return 0;
    }
    
    int last = prices[0], profits = 0;
    for (int i = 1; i < pricesSize; i++)
    {
        if (prices[i] > last)
        {
            profits += prices[i] - last;
        }
        last = prices[i];
    }
    return profits;
}