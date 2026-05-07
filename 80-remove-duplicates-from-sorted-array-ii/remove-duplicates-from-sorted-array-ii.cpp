class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if (nums.size() <=2) return nums.size();

        int k = 2;
        for (int i=2; i<nums.size(); i++) {
            // more than 2 character
            if (nums[i] == nums[k-2]) continue;
            nums[k] = nums[i];
            k++;
        }
        return k;
    }
};