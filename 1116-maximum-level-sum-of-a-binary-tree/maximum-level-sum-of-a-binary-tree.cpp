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
    int maxLevelSum(TreeNode* root) {
        int max = INT_MIN;  // contain negative numbers
        int level = 0;
        int ans = 0;

        // bfs
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            level += 1; // every iteration plus 1
            int sum = 0;    // accumlate current level sum
            int size = q.size();

            for (int i=0; i<size; i++) {
                TreeNode* cur = q.front();
                q.pop();
                sum += cur->val;

                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }

            if (sum > max) {
                max = sum;
                ans = level; 
            }
        }

        return ans;
    }
};