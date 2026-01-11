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
    bool traversal (TreeNode* root, int counter) {
        if (root->left == NULL && root->right == NULL && counter == 0)
            return true;
        if (root->left == NULL && root->right == NULL)
            return false;
        
        // left
        if (root->left) {
            counter -= root->left->val;
            if (traversal(root->left, counter)) return true;
            counter += root->left->val;
        }

        // middle

        if (root->right) {
            counter -= root->right->val;
            if (traversal(root->right, counter)) return true;
            counter += root->right->val;
        }

        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return false;
        return traversal(root, targetSum - root->val);
    }
};