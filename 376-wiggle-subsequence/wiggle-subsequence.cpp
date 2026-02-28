class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) 
            return nums.size(); 
        
        int prevdiff = 0;
        int curdiff = 0;
        int ans = 1;    //defaule right have one corner
        for (int i=0; i<nums.size()-1; i++) {
            curdiff = nums[i+1] - nums[i];
            if ((prevdiff <= 0 && curdiff > 0) || (prevdiff >= 0 && curdiff < 0)) {
                ans ++;
                prevdiff = curdiff;
            }
        }
        return ans;
    }
};