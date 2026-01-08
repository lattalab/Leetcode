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
    int getHeight (TreeNode* root) {
        if (root == NULL) return 0;

        int left = getHeight(root->left);
        if (left == -1) return -1;
        int right = getHeight(root->right);
        if (right == -1) return -1;

        int diff = abs(left - right);
        if (diff > 1) return -1;    // not balanced tree
        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        int test = getHeight(root);
        if (test == -1) return false;
        else return true;
    }
};