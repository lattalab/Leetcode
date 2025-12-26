class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int left = 0, right=len-1;
        int mid = len/2;
        while(left <= right){
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target){
                right = mid - 1;
                mid = (left + right) / 2;
            } else {
                left = mid + 1;
                mid = (right + left) / 2;
            }
        }
        return -1;
    }
};