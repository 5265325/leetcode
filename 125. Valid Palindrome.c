bool isPalindrome(char* s) {
    int i = 0, j = strlen(s) - 1;
    while (i < j) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 32;
        }
        if ((s[i] < 'a' || s[i] > 'z') && (s[i] < '0' || s[i] > '9')) {
            i++;
            continue;
        }
        
        if (s[j] >= 'A' && s[j] <= 'Z') {
            s[j] += 32;
        }
        if ((s[j] < 'a' || s[j] > 'z') && (s[j] < '0' || s[j] > '9')) {
            j--;
            continue;
        }
        
        if (s[i] != s[j]) {
            return false;
        }
        
        i++;
        j--;
    }
    return true;
}