int myAtoi(char* str) {
    while (*str == ' ') {
        str++;
    }
    
    bool is_negative;
    if (*str == '-') {
        is_negative = true;
        str++;
    }
    else {
        is_negative = false;
        if (*str == '+') {
            str++;
        }
    }
    
    int num = 0;
    while (*str >= '0' && *str <= '9') {
        int64_t value = (int64_t)num * 10 + (*str - '0');
        if (value > INT_MAX) {
            return is_negative ? INT_MIN : INT_MAX;
        }
        num = (int)value;
        str++;
    }
    return is_negative ? 0 - num : num;
}