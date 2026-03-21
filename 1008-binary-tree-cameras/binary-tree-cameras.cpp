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
    int result = 0;
    // define:
    // 0: not cover
    // 1: have camera
    // 2: covered
    int dfs (TreeNode* cur) {
        if (cur == NULL) return 2;
        // left
        int left = dfs(cur->left);
        // right
        int right = dfs(cur->right);
        // middle
        if (left == 2 && right == 2) return 0;
        if (left == 0 || right == 0) {
            result++;
            return 1;
        }
        if (left == 1 || right == 1) return 2;
        // shouldn't be occured
        return -1; 
    }
public:
    int minCameraCover(TreeNode* root) {
        result = 0;
        int val = dfs(root);
        // if root is not cover, then assign the camera
        if (val == 0) {
            result++;
        }
        return result;
    }
};