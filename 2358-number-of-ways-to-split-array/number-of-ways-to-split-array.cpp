class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        // prefix sum
        long long sum = 0;
        for (int i=0; i<nums.size(); i++) {
            sum += nums[i];
        }

        // divide
        long long left = 0;
        int count = 0;
        for (int i=0; i<nums.size()-1; i++) {
            left += nums[i];
            long long right = sum - left;
            if (left >= right) count++;
        }

        return count;
    }
};