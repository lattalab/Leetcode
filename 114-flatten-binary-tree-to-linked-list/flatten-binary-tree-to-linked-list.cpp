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
    TreeNode* dfs(TreeNode *root, TreeNode *tail) {
        // find leaf node
        if (!root) return tail;
        
        // preserve for left and right child
        TreeNode *left = root->left;
        TreeNode *right = root->right;

        // middle
        tail->right = root;
        tail = tail->right;

        tail->left = NULL;
        tail->right = NULL;
        // left
        tail = dfs(left, tail);
        // right
        tail = dfs(right, tail);

        return tail;
    }
    void flatten(TreeNode* root) {
        // edge case
        if (!root || (!root->left && !root->right)) return ;

        TreeNode *dummy_head = new TreeNode();
        TreeNode *tail = dummy_head;

        dfs(root, tail);
        
        TreeNode *head = dummy_head->right;
        delete dummy_head;
        root = head;
    }
};