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
    void bfs(TreeNode* root) {

    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if (root != NULL) q.push(root);
        vector<vector<int>> result;
        while(!q.empty()){
            
            // put value
            int size = q.size();
            vector<int> v;

            for (int i=0; i<size; i++){
                TreeNode* cur = q.front();
                q.pop();
                v.push_back(cur->val);
                // put child into queue
                if (cur->left)  q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }

            result.push_back(v);
        }
        return result;
    }
};