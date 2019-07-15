struct TreeNode * getTree(int* nums, int l,int r) {
    if (l <= r) {
        int mid = (l+r)/2;
        struct TreeNode * node = malloc(sizeof(struct TreeNode));
        node ->val = nums[mid];
        node->left = getTree(nums, l, mid - 1);
        node->right = getTree(nums, mid + 1, r);
        return node;
    }
    return NULL;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (nums == NULL || numsSize == 0) {
        return NULL;
    }
    return getTree(nums, 0, numsSize - 1);
}