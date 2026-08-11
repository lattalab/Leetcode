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
        
        maximum = max(maximum, root->val);
        // preorder
        if (root->val >= maximum) {
            ans++;
        }
        dfs(root->left, maximum);
        dfs(root->right, maximum);
    }
    int goodNodes(TreeNode* root) {
        int max = root->val;
        dfs(root, max);
        return ans;
    }
};