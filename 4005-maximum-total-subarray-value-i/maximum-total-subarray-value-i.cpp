class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long max_num = 0;
        long long min_num = INT_MAX;
        for (int i=0; i<nums.size(); i++) {
            max_num = max(max_num, (long long) nums[i]);
            min_num = min(min_num, (long long) nums[i]);
        }
        return (max_num - min_num) * k;
    }
};