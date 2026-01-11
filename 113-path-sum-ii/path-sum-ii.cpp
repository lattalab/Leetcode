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
    void traversal (TreeNode* root, int counter, vector<int> &path, vector<vector<int>> &paths) {
        if (root->left == NULL && root->right == NULL && counter == 0) {
            paths.push_back(path);
        }

        // left
        if (root->left) {
            counter -= root->left->val;
            path.push_back(root->left->val);
            traversal(root->left, counter, path, paths);
            counter += root->left->val;
            path.pop_back();
        }

        // middle

        // right
        if (root->right) {
            counter -= root->right->val;
            path.push_back(root->right->val);
            traversal(root->right, counter, path, paths);
            counter += root->right->val;
            path.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        vector<vector<int>> paths;
        if (root == NULL) return paths;
        path.push_back(root->val);
        traversal(root, targetSum - root->val, path, paths);
        return paths;
    }
};