class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int slow = 0, fast = 0;
        while (slow < n) {
            // move until reach 0
            while (slow < n && nums[slow] != 0)
                slow++;
            fast = slow + 1;
            // move until reach non-zero
            while (fast < n && nums[fast] == 0)
                fast++;
            
            if (slow < n && fast < n)
                swap(nums[slow], nums[fast]);

            slow = slow + 1;
        }
    }
};