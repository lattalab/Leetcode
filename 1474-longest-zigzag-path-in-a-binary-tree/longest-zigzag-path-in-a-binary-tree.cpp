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
    int maxZigZag(TreeNode* curr, int direction, int length) {
        if (curr == NULL) 
            return length-1;    // because we assume each node is valid, so deduct empty node

        // define right: direction=1, left = direction=0
        if (direction) {
            return maxZigZag(curr->right, 0, length+1);
        }
        else {
            return maxZigZag(curr->left, 1, length+1);
        }
    } 
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        // tree traversal
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            for (int i=0; i<size; i++) {
                TreeNode *cur = q.front();
                q.pop();

                ans = max(ans, maxZigZag(cur, 0, 0));
                ans = max(ans, maxZigZag(cur, 1, 0));
                
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }

        return ans;
    }
};