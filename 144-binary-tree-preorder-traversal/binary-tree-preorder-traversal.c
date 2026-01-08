/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void solve(struct TreeNode* root, int* ans, int* returnSize) {
    if (root == NULL) return;

    ans[(*returnSize)++] = root->val;
    solve(root->left, ans, returnSize);
    solve(root->right, ans, returnSize);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;

    int MAX_NODE = 200;  // leetcode constrain
    int* ans = malloc(sizeof(struct TreeNode) * MAX_NODE);
    solve(root, ans, returnSize);

    return ans;
}