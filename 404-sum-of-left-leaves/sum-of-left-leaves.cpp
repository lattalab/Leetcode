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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) return 0;

        // left
        int leftValue = sumOfLeftLeaves(root->left);

        // judge from whethe left child exists or not
        if (root->left != NULL && root->left->left == NULL && root->left->right == NULL) {
            leftValue += root->left->val;
        }

        // right
        int rightValue = sumOfLeftLeaves(root->right);

        return leftValue + rightValue;
    }
};