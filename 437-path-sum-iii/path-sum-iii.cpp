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
    unordered_map<long long, long long> mp;
    long long ans = 0;
    void dfs(TreeNode* root, long long currentSum, int targetSum) {
        if (root == NULL) return ;

        // middle
        currentSum += root->val;

        // Test currentSum - target == prefixSum (subarraySum)
        // Check whether there is a previous prefix sum
        // such that currentSum - previousSum == targetSum
        if (mp.count(currentSum - targetSum)) {
            ans += mp[currentSum - targetSum];
        }

        // Add current prefix sum after checking
        mp[currentSum]++;

        // left
        dfs(root->left, currentSum, targetSum);
        // right
        dfs(root->right, currentSum, targetSum);

        // backtracking: restore the sum
        mp[currentSum]--;
        currentSum -= root->val;
    }
    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;

        dfs(root, 0, targetSum);

        return ans;
    }
};