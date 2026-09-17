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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // boundary case
        if (root == NULL) return {};

        // record the zigzag direction
        bool left = true;
        
        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> ans;
        while (!q.empty()) {
            int size = q.size();

            // traversal current level
            vector<int> temp;
            for (int i=0; i<size; i++) {
                TreeNode *cur = q.front();
                q.pop();
                temp.push_back(cur->val);

                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            
            // ziazag should chanage direction
            if (!left) reverse(temp.begin(), temp.end());

            // modify the direction
            left = !left;

            ans.push_back(temp);
        }

        return ans;
    }
};