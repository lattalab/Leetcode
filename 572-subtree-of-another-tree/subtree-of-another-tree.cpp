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
    bool isSameTree (TreeNode* left, TreeNode* right) {
        // 4. cases
        if (left == NULL && right != NULL) return false;
        else if (left != NULL && right == NULL) return false;
        else if (left == NULL && right == NULL) return true;
        else if (left->val != right->val) return false;

        // now this level has the same value
        // move on next level
        bool outside = isSameTree(left->left, right->left);   
        bool inside = isSameTree(left->right, right->right);    
        bool isSame = outside && inside;                    
        return isSame;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // find subtree in root first (postorder)
        if (root == NULL && subRoot != NULL) return false;
        else if (root != NULL && subRoot == NULL) return false;
        else if (root == NULL && subRoot == NULL) return true;
        if ( isSameTree(root, subRoot) ) {
            // it may contain multiple node to match `root->val == subRoot->val`
            // therefore, it bad to use such condition
            return true;
        }
        else {
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }
        
    }
};