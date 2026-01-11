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
    TreeNode* traversal(vector<int>& inorder, int inorderBegin, int inorderEnd, vector<int>& postorder, int postorderBegin, int postorderEnd) {
        if (postorderBegin == postorderEnd) return NULL;

        // 1. last index of postorder will be root
        int root_value = postorder[postorderEnd -1];
        TreeNode* root = new TreeNode(root_value);

        // leaf node
        if (postorder.size() == 1) return root;

        // 2. find del
        int delimiterIndex;
        for (delimiterIndex=inorderBegin; delimiterIndex<inorderEnd; delimiterIndex++) {
            // leetcode make sure it is unique value
            if (inorder[delimiterIndex] == root_value) break;
        }

        // 3. divide inorder
        int leftInorderBegin = inorderBegin;
        int leftInorderEnd = delimiterIndex;
        // [delimiterIndex + 1, end)
        int rightInorderBegin = delimiterIndex + 1;
        int rightInorderEnd = inorderEnd;

        // 4. divide postorder 
        // the number of left subtree should be the same
        // [0, leftInorder.size)
        int leftPostorderBegin =  postorderBegin;
        int leftPostorderEnd = postorderBegin + delimiterIndex - inorderBegin;
        // [leftInorder.size(), end)
        int rightPostorderBegin = postorderBegin + (delimiterIndex - inorderBegin);
        int rightPostorderEnd = postorderEnd - 1;

        // 5. recursion
        root->left = traversal(inorder, leftInorderBegin, leftInorderEnd,  postorder, leftPostorderBegin, leftPostorderEnd);
        root->right = traversal(inorder, rightInorderBegin, rightInorderEnd, postorder, rightPostorderBegin, rightPostorderEnd);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return NULL;
        return traversal(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};