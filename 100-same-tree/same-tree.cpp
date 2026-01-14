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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 4. cases
        if (p == NULL && q != NULL) return false;
        else if (p != NULL && q == NULL) return false;
        else if (p == NULL && q == NULL) return true;
        else if (p->val != q->val) return false;

        // now this level has the same value
        // move on next level
        bool outside = isSameTree(p->left, q->left);   
        bool inside = isSameTree(p->right, q->right);    
        bool isSame = outside && inside;                    
        return isSame;
    }
};