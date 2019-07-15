bool _isValidBST(struct TreeNode* root, long mn, long mx){
    if(!root)
        return true;
    if(root->val <= mn || root->val >= mx)
        return false;
    return _isValidBST(root->left, mn, root->val) && _isValidBST(root->right, root->val, mx);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isValidBST(struct TreeNode* root) {
    return _isValidBST(root, LONG_MIN, LONG_MAX);
}