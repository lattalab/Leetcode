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
    void inorder (TreeNode* root, vector<int>& nums) {
        if (root == NULL) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
    TreeNode* balanced (vector<int>& inorder, int l, int r) {
        
        if (l > r) return NULL;
        
        int mid = (l+r) / 2;
        TreeNode* root = new TreeNode(inorder[mid]);
        root->left = balanced(inorder, l, mid-1);
        root->right = balanced(inorder, mid+1, r);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);
        return balanced(nums, 0, nums.size()-1);
    }
};