typedef struct {
    int * array;
    int pointer;
    int maxSize;
    int min;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
    MinStack * result = malloc(sizeof(MinStack));
    result->array = malloc(sizeof(int) * maxSize);
    result->maxSize = maxSize;
    result->pointer = 0;
    result->min = 2147483647;
    return result;
}

void minStackPush(MinStack* obj, int x) {
    if(x < obj->min) {
        obj->min = x;
    }
    obj->array[obj->pointer++] = x;
}

void minStackPop(MinStack* obj) {
    if(obj->array[obj->pointer - 1] == obj->min) {
        obj->pointer--;
        obj->min = 2147483647;
        for(int i = 0; i < obj->pointer; i++) {
            if(obj->array[i] < obj->min)
                obj->min = obj->array[i];
        }
    }
    else {
        obj->pointer--;
    }
}

int minStackTop(MinStack* obj) {
    return obj->array[obj->pointer - 1];
}

int minStackGetMin(MinStack* obj) {
    return obj->min;
}

void minStackFree(MinStack* obj) {
    free(obj->array);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */