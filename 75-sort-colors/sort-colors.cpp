class Solution {
public:
    void sortColors(vector<int>& nums) {
        int bottom = 0;
        int middle = 0;
        int top = nums.size() - 1;
        while (middle <= top) {
            if (nums[middle] < 1) {
                swap(nums[bottom], nums[middle]);
                bottom++;
                middle++;
            }
            else if (nums[middle] > 1) {
                swap(nums[top], nums[middle]);
                top--;
            }
            else {
                middle++;
            }
        }
    }
};