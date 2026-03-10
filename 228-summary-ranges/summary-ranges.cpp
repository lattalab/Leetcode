class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        for (int start = 0; start < nums.size(); ) {
            int end = start;
            while (end + 1 < nums.size() && nums[end+1] == nums[end] + 1) end++;

            // put result
            if (nums[end] == nums[start]) {
                ans.push_back(to_string(nums[start]));
            }
            else {
                string s = to_string(nums[start]);
                s += "->";
                s += to_string(nums[end]);
                ans.push_back(s);
            }

            // update pointer
            start = end + 1;
        }

        return ans;
    }
};