/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root) {
    struct TreeNode *cur = root;
    while (cur) {
        if (cur->left) {
            struct TreeNode *temp = cur->left;
            // find rightmost in left subtree;
            // if no right child, rightmost node is the root itself
            struct TreeNode *rightmost = temp;
            while (rightmost->right) {
                rightmost = rightmost->right;
            }
            // connect rightmost node with root->right
            // combine left and right subtree
            rightmost->right = cur->right;
            // update the whole tree;
            cur->right = temp;
            cur->left = NULL;
        }
        cur = cur->right;
    }
}