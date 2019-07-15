/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    int lenth_l, lenth_r;
    
    if (root == NULL) {
        return 0;
    }
    
    lenth_l = maxDepth(root->left);
    lenth_r = maxDepth(root->right);
    
    return lenth_l > lenth_r ? lenth_l + 1 : lenth_r + 1;
}