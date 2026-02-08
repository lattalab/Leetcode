/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int compareHeight (struct TreeNode* root) {
    // end condition
    if (root == NULL) return 0;

    int left = compareHeight(root->left);
    // pruning
    if (left == -1) return -1;
    int right = compareHeight(root->right);
    // pruning
    if (right == -1) return -1;

    int diff = abs(left - right);
    if (diff > 1) return -1;
    else return fmax(left, right) + 1;
}
bool isBalanced(struct TreeNode* root) {
    int test = compareHeight(root);
    if (test == -1) return false;
    else return true;
}