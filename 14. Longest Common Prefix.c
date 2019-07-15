char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        return "";
    }
    if (strsSize == 1) {
        return strs[0];
    }
    
    int prefix = 0;
    char * new;
    while (1) {
        if (strs[0][prefix] == '\0') {
            goto exit;
        }
        for (int i = 1; i < strsSize; i++) {
            if (strs[0][prefix] != strs[i][prefix]) {
                goto exit;
            }
        }
        prefix++;
    }
    
exit:
    new = malloc(prefix + 1);
    memcpy(new, strs[0], prefix);
    new[prefix] = 0;
    return new;
}