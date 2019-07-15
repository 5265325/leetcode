/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes) {
    int ** output = malloc(sizeof(int *) * numRows);
    *columnSizes = malloc(sizeof(int) * numRows);
    
    int * curr_line, * last_line;
    for (int i = 1; i <= numRows; i++) {
        curr_line = malloc(sizeof(int) * i);
        (*columnSizes)[i - 1] = i;
        
        for (int j = 0; j < (i + 1) / 2; j++) {
            if (j == 0) {
                curr_line[0] = 1;
                curr_line[i - 1] = 1; 
            }
            else if (j >= 1){
                curr_line[j] = last_line[j - 1] + last_line[j];
                curr_line[i - 1 - j] = curr_line[j];
            }
        }
        output[i - 1] = curr_line;
        last_line = curr_line;
    }
    return output;
}