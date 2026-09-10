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
    // critical point: you can return both sum and count at the same time by pair
    pair<int, int> traversal (TreeNode *root) {
        if (root == NULL) {
            return {0, 0};
        }

        // apply postorder
        auto left = traversal(root->left);
        auto right = traversal(root->right);
        // middle
        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;
        // based on the question description, check if current node value equal to average of subtree
        int avg = round(sum / count);
        if (avg == root->val) {
            ans++;
        }

        return {sum, count};
    }
    int averageOfSubtree(TreeNode* root) {
        traversal(root);
        return ans;
    }
};