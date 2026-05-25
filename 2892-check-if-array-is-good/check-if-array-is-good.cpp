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
        vector<bool> test(ExpectedLen, false);
        int count = 1;
        for (int i=0; i<nums.size(); i++) {
            int target = nums[i];
            if (test[target] == false) {
                test[target] = true;
            }
            else {
                if (target != max) {
                    return false;
                }
                else {
                    count++;
                    if (count != 2) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};