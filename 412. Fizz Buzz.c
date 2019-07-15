/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    const char * data[] = {"", "Fizz", "Buzz", "FizzBuzz"};
    char ** output = (char *)malloc(n * sizeof(char *));
    
    for (int i = 1; i <= n; i++)
    {
        int flag = ((i % 3) == 0) | (((i % 5) == 0) << 1);
        // char * buf = malloc(sizeof(data[0]) + 1);
        if (flag == 0)
        {
            // sprintf(buf, "%d", i);
            buf = strdup();
        }
        else
        {
            strcpy(buf, data[flag]);
        }
        *(output + i - 1) = buf;
    }
    
    *returnSize = n;
    return output;
}