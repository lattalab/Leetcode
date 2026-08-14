class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = (n+1) * n / 2;
        int sum = 0;
        for (int i=0; i<nums.size(); i++) {
            sum += nums[i];
        }
        return total - sum;
    }
};