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
    int ans = 0;
    void dfs(TreeNode *root, int maximum) {
        
        if (root == NULL) return ;
        
        // preorder
        // Check whether the current node is good
        if (root->val >= maximum) {
            ans++;
            maximum = root->val;
        }
        dfs(root->left, maximum);
        dfs(root->right, maximum);
    }
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return ans;
    }
};