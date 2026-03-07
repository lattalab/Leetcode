struct cmp {
    bool operator() (int a, int b) {
        return abs(a) > abs(b);
    }
};
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        // 1. sort by absolute value from large to small
        sort(nums.begin(), nums.end(), cmp());
        // 2. make all negative to be positive
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] < 0 && k > 0) {
                nums[i] = -nums[i];
                k--;
            }
        }
        // 3. if k value still greater than 0, select the min value to flip until k reach 0
        while (k>0) {
            nums[nums.size()-1] *= -1;
            k--;
        }
        // 4. accumulate sum
        int sum = 0;
        for (int i=0; i<nums.size(); i++) {
            sum += nums[i];
        }
        return sum;
    }
};