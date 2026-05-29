class Solution {
public:
    int DigitSum(int num) {
        int sum = 0;
        while (num) {
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int min = 1e5;
        for (int i=0; i<nums.size(); i++) {
            nums[i] = DigitSum(nums[i]);
            if (nums[i] < min) min = nums[i];
        }
        return min;
    }
};