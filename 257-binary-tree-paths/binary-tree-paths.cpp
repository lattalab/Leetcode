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
    void traverse (TreeNode* root, vector<int> &path, vector<string> &result) {
        // before deal with leaf node, we need to append the current node first
        path.push_back(root->val);    // middle
        
        // arrive at leaf node
        if (root->left == NULL && root->right == NULL) {
            string p;
            for (int i=0; i<path.size()-1; i++) {
                p += to_string(path[i]);
                p += "->";
            }
            p += to_string(path[path.size()-1]);
            result.push_back(p);
            return;
        }

        if (root->left) {
            traverse(root->left, path, result);
            path.pop_back(); // 回溯
        } 
        if (root->right) {
            traverse (root->right, path, result);
            path.pop_back(); // 回溯
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> path;
        if (root == NULL) return result;
        traverse(root, path, result);
        return result;
    }
};