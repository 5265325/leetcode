int romanToInt(char* s) {
    if (s == NULL) {
        return 0;
    }
    
    int num = 0;
    char * p = s;
    while (*p != 0) {
        switch (*p) {
            case 'I':
                if (*(p+1) == 'V') {
                    num += 4;
                    p++;
                }
                else if (*(p+1) == 'X') {
                    num += 9;
                    p++;
                }
                else {
                    num += 1;
                }
                break;
            case 'V' :
                num += 5;
                break;
            case 'X':
                if (*(p+1) == 'L') {
                    num += 40;
                    p++;
                }
                else if (*(p+1) == 'C') {
                    num += 90;
                    p++;
                }
                else {
                    num += 10;
                }
                break;
            case 'L':
                num += 50;
                break;
            case 'C':
                if (*(p+1) == 'D') {
                    num += 400;
                    p++;
                }
                else if (*(p+1) == 'M') {
                    num += 900;
                    p++;
                }
                else {
                    num += 100;
                }
                break;
            case 'D':
                num += 500;
                break;
            case 'M':
                num += 1000;
                break;
            default:
                return 0;
        }
        p++;
    }
    return num;
}