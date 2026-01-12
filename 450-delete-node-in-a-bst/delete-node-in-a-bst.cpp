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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return root; // not find in the BST

        if (root->val == key) {
            // 1. leaf node -> directly delete
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }
            // 2. have only 1 child
            //left
            if (root->left != NULL && root->right == NULL) {
                TreeNode *tmp = root;
                root = root->left;
                delete tmp;
                return root;
            }
            //right
            if (root->left == NULL && root->right != NULL) {
                TreeNode *tmp = root;
                root = root->right;
                delete tmp;
                return root;
            }

            // 4. have both child -> put left subtree into right subtree
            if (root->left != NULL && root->right != NULL) {
                TreeNode* cur = root->right;
                // find left most node in right subtree
                while(cur->left != NULL) {
                    cur = cur->left;
                }
                cur->left = root->left;
                TreeNode* tmp = root;
                root = root->right;
                delete tmp;
                return root;
            }
        }

        // recursion
        if (root->val > key) root->left = deleteNode(root->left, key);
        if (root->val < key) root->right = deleteNode(root->right, key);
        return root;
    }
};