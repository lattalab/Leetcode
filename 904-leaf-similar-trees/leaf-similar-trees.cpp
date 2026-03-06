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
    void postorder(TreeNode* root, vector<int> &nums) {
        if (root->left == NULL && root->right == NULL) {
            nums.push_back(root->val);
            return;
        }

        if (root->left) postorder(root->left, nums);
        if (root->right) postorder(root->right, nums);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        // record tree1
        vector<int> seq1;
        postorder(root1, seq1);
        // record tree2
        vector<int> seq2;
        postorder(root2, seq2);
        // comparing sequence
        if (seq1.size() != seq2.size()) return false;
        for (int i=0; i<seq1.size(); i++) {
            if (seq1[i] != seq2[i])
                return false;
        }
        return true;
    }
};