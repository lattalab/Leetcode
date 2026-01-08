/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    if (root == NULL) return 0;

    int left = minDepth( root->left );
    int right = minDepth ( root->right );

    // 3 cases:
    if (root->left == NULL && root->right != NULL)
        return right+1;
    else if (root->left != NULL && root->right == NULL) 
        return left+1;
    
    int result = ( left > right ) ? right : left;
    return 1 + result;
}