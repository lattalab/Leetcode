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
struct cmp {
    bool operator() (TreeNode *a, TreeNode *b){
        return a->val <= b->val;
    }
};
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> pq;
        if (root != NULL) pq.push(root);
        vector<int> ans;
        while (!pq.empty()) {
            int size = pq.size();
            int max = pq.front()->val;
            for (int i=0; i<size; i++) {
                TreeNode *cur = pq.front();
                pq.pop();
                max = (cur->val > max) ? cur->val : max;
                if (cur->left)  pq.push(cur->left);
                if (cur->right) pq.push(cur->right);
            }
            ans.push_back(max);
        }
        return ans;
    }
};