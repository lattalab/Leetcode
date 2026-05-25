class Solution {
public:
    bool isGood(vector<int>& nums) {
        // finding maximum
        int max = -1;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] > max) {
                max = nums[i];
            }
        }
        int ExpectedLen = max + 1;
        if (nums.size() != ExpectedLen) return false;

        // trace for number occurance
        vector<int> count(ExpectedLen, 0);
        for (int i=0; i<nums.size(); i++) {
            int curr = nums[i];
            // check if [1, n-1] appear more than once
            if (curr <= max-1 && count[curr] > 0) {
                return false;
            }
            // check if n appear at most twice
            if (curr == max && count[curr] > 1) {
                return false;
            }
            count[curr]++;
        }
        return true;
    }
};