class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less;
        vector<int> greater;
        int count = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] < pivot) {
                less.push_back(nums[i]);
            }
            else if (nums[i] == pivot) {
                count ++;
            }
            else {
                greater.push_back(nums[i]);
            }
        }
        // merge
        vector<int> ans;
        for (int i=0; i<less.size(); i++) {
            ans.push_back(less[i]);
        }
        while (count != 0) {
            ans.push_back(pivot);
            count--;
        }
        for (int j=0; j<greater.size(); j++) {
            ans.push_back(greater[j]);
        }
        return ans;
    }
};