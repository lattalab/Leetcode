class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // leetcode said -100 <= nums[i] <= 100
        int table[210] = {0}; 

        int slow = 0;
        for (int fast=0; fast<nums.size(); fast++) {
            if (table[ (nums[fast]+100) ] == 0) {
                // first appear, store into table, and increment slow pointer
                table[ (nums[fast]+100) ]++;
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};