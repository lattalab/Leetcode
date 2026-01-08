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
    bool compare (TreeNode* left, TreeNode* right) {
        // examine for null node
        if (left == NULL && right == NULL) return true;
        else if (left == NULL && right != NULL) return false;
        else if (left != NULL && right == NULL) return false;
        else if (left->val != right->val) return false;

        // 不為空有兩種情況，接著處理這層相同的情況 (用下一層決定)
        bool outside = compare(left->left, right->right);
        bool inside  = compare(left->right, right->left);
        return outside && inside;
    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return compare(root->left, root->right);
    }
};