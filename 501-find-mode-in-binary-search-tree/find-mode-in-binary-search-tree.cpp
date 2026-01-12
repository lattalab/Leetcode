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
    TreeNode* prev = NULL;
    int count = 0;
    int MaxCount = 0;
    void traversal(TreeNode* cur, vector<int> &res) {
        if (cur == NULL) return;

        traversal(cur->left, res);

        if (prev == NULL) {
            count = 1;
        }
        else if (prev != NULL && prev->val == cur->val) {
            count++;
        }
        else {
            // 相鄰值不同
            count = 1;
        }
        prev = cur;

        if (MaxCount == count) {
            res.push_back(cur->val);
        }

        if (MaxCount < count) {
            MaxCount = count;
            res.clear();
            res.push_back(cur->val);
        }
        
        traversal(cur->right, res);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};