class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        int left = 1;
        for (int i=0; i<nums.size(); i++){
            ans[i] *= left;
            left *= nums[i];
        }

        int right = 1;        
        for (int j=nums.size()-1; j>=0; j--) {
            ans[j] *= right;
            right *= nums[j];
        }
        return ans;
    }
};