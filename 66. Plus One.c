/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
//     char * string = malloc(digitsSize + 1);
//     int digit = 0;
//     for (int i = 0; i < digitsSize; i++) {
//         digit += digits[1] * (int)(pow(10, i));
//     }
    
//     digit += 1;
//     sprintf(string, "%u", digit);
    
//     for () {
        
//     }
    
    bool carry = true;
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (carry && ++digits[i] >= 10) {
            digits[i] = 0;
        }
        else {
            carry= false;
            break;
        }
    }
    
    if (carry) {
        int * new_digits = malloc(sizeof(int) * (digitsSize + 1));
        memcpy(&new_digits[1], digits, digitsSize * sizeof(int));
        new_digits[0] = 1;
        *returnSize = digitsSize + 1;
        return new_digits;
    }
    
    *returnSize = digitsSize;
    return digits;
}