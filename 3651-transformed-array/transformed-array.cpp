class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        int n = nums.size();
        for (int i=0; i<n; i++) {
            int step = abs(nums[i]);
            if (nums[i] > 0) {
                result[i] = nums[ (i+step) % n ];
            }
            else if (nums[i] < 0) {
                result[i] = nums[ (((i-step) % n) + n) %n ];
            }
            else { 
                // nums[i] == 0 
                result[i] = 0;
            }
        }
        return result;
    }
};