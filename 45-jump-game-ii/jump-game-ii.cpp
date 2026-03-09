class Solution {
public:
    int jump(vector<int>& nums) {
        int current = 0;
        int farest = 0;
        int ans = 0;
        
        for (int i=0; i<nums.size()-1; i++) {
            farest = max(farest, i+nums[i]);
            if (i == current) {
                current = farest;
                ans++;
            }
        }
        return ans;
    }
};