char* countAndSay(int n) {
    if(n == 1) return "1";

    char * cur = malloc(2);
    char * temp;
    cur[0] = '1';
    cur[1] = 0;

    int len, idx, j, count;
    for(int i = 2; i <= n; i++) {

        len = strlen(cur);
        temp = malloc(3 * len);
        memset(temp, 0, 3 * len);
        count = 1;
        for(idx = 1, j = 0; idx < len; idx++) {
            if(cur[idx] == cur[idx - 1]) count++;
            else {
                temp[j++] = '0' + count;
                temp[j++] = cur[idx - 1];
                count = 1;
            }
        }
        temp[j++] = '0' + count;
        temp[j] = cur[len - 1];
        free(cur);
        cur = temp;
    }
    return cur;
}