/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    int **result = NULL;
	if (root == NULL) {
	    *columnSizes = NULL;
	    *returnSize = 0;
	    return NULL;
	}

	*columnSizes = NULL;
	*returnSize = 0;

	struct TreeNode **queue = (struct TreeNode **)malloc(sizeof(struct TreeNode *));
	struct TreeNode *pop;
	int start = 0, end = 0, length = 0;
	queue[end++] = root;
	length = 1;

	while (length > 0) {
	    result = (int **)realloc(result, (*returnSize+1)*sizeof(int *));
	    result[*returnSize] = (int *)malloc(sizeof(int)*length);
	    *columnSizes = (int *)realloc(*columnSizes, (*returnSize+1)*sizeof(int));
	    (*columnSizes)[*returnSize] = length;

	    for (int i=0; i<length; i++) {
	        pop = queue[start++];
	        result[*returnSize][i] = pop->val;
	        if (pop->left) {
	            queue = (struct TreeNode **)realloc(queue, sizeof(struct TreeNode *)*(end+1));
	            queue[end++] = pop->left;
	        }
	        if (pop->right) {
	            queue = (struct TreeNode **)realloc(queue, sizeof(struct TreeNode *)*(end+1));
	            queue[end++] = pop->right;
	        }
	    }
	    length = end-start;
	    *returnSize += 1;
	}

	return result;
}