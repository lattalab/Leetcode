/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    // end case
    if (root == NULL) return root;
    
    if (root->val == key) {
        // 1. leaf node -> directly delete
        if (root->left == NULL && root->right == NULL) {
            free(root);
            // as for parent, it connect to nullptr
            return NULL;
        }
        // 2. have only 1 child
        // left
        else if (root->left && !root->right) {
            struct TreeNode *temp = root->left;
            free(root);
            return temp;
        }
        // right
        else if (!root->left && root->right) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        // 3. have both child -> put left subtree into right subtree
        else {
            // finding the smallest(left side) in right subtree
            struct TreeNode* cur = root->right;
            while (cur->left != NULL) {
                cur = cur->left;
            }
            // replace the root->val with `cur->val`
            root->val = cur->val;
            // Delete the successor node from the right subtree
            root->right = deleteNode(root->right, cur->val);
        }
    }
    else if (root->val < key) {
        // make recursive function modify right subtree
        root->right = deleteNode(root->right, key);
    }
    else {  // root->val > key
        root->left = deleteNode(root->left, key);
    }

    return root;
}