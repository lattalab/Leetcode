class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        
        int size = nums.size();
        vector<int> ans(size, 0);
        
        // accumlate the right sum
        int rightsum = 0;
        for (int i=size-1; i>=0; i--) {
            ans[i] = rightsum;
            rightsum += nums[i];
        }

        // calcuate the left sum
        int leftsum = 0;
        for (int i=0; i<size; i++) {
            ans[i] = abs(ans[i] - leftsum);
            leftsum += nums[i];
        }

        return ans;
    }
};