/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pathsum(TreeNode* root, int num) {
        // encouter null, no value, early stopping
        if (root == NULL) {
            return 0;
        }

        int cur = (num << 1) + root->val;
        // encounter leaf node, return current number
        if (root->left == NULL && root->right == NULL) {
            return cur;
        }

        int left = pathsum(root->left, cur);
        int right = pathsum(root->right, cur);
        return left + right;
    }
    int sumRootToLeaf(TreeNode* root) {
        return pathsum(root, 0);
    }
};