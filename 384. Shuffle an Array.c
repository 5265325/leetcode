typedef struct {
    int size;
    int * nums;
    int * original;
} Solution;

Solution* solutionCreate(int* nums, int size) {
    Solution* result = malloc(sizeof(Solution));
    result->size = size;
    result->nums = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        result->nums[i] = nums[i];
    }
    result->original = nums;
    return result;
}

/** Resets the array to its original configuration and return it. */
int* solutionReset(Solution* obj, int *returnSize) {
    if (obj == NULL) {
        return NULL;
    }
    *returnSize = obj->size;
    return obj->original;
}

#define random(x) (rand()%x)
/** Returns a random shuffling of the array. */
int* solutionShuffle(Solution* obj, int *returnSize) {
    if (obj == NULL) {
        return NULL;
    }
    
    for(int i = 0; i < obj->size; i++)
    { 
        int randNum = rand()%(obj->size);
        
        int temp = obj->nums[i];
        obj->nums[i] = obj->nums[randNum];
        obj->nums[randNum] = temp;
    }
    *returnSize = obj->size;
    return obj->nums;
}

void solutionFree(Solution* obj) {
    if (obj == NULL) {
        return NULL;
    }
    free(obj->nums);
    free(obj->original);
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * struct Solution* obj = solutionCreate(nums, size);
 * int* param_1 = solutionReset(obj);
 * int* param_2 = solutionShuffle(obj);
 * solutionFree(obj);
 */