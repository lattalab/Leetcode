class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex) {
        if (path.size() >= 2) {
            result.push_back(path);
        }

        unordered_set<int> st;
        for (int i=startIndex; i<nums.size(); i++) {
            if ( (!path.empty()) && (nums[i] < path.back()) || st.find(nums[i]) != st.end() ) {
                // 1. path 非空且最後一個元素大於目前要插入的元素
                // 2. 這個元素之前沒被用過 (防止重複子集合)
                continue;
            }
            st.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        result.clear();
        path.clear();
        backtracking(nums, 0);
        return result;
    }
};