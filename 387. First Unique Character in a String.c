int firstUniqChar(char* s) {
    
    int hash[256];
    for (int i = 0; i < 256; i++) {
        hash[i] = 0;
    }
    
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        hash[s[i]]++;
    }
    
    for (int i = 0; i < len; i++) {
        if (hash[s[i]] == 1) {
            return i;
        }
    }
    return -1;
}