int climbStairs(int n) {
    int num1 = 1;
	int num2 = 2;
	int tmp = 0;
	int i = 0;
	if (n == 1) {
		return 1;
	}
    if (n == 2) {
        return 2;
    }
	else
	{
		for (i = 2; i < n; i++)
		{
			tmp = num1 + num2;
			num1 = num2;
			num2 = tmp;
		}
		return tmp;
	}
}