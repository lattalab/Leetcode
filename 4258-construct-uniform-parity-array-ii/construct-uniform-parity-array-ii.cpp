class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        // check for all even
        bool even = true;
        for (int i=0; i<nums1.size(); i++) {
            if (nums1[i] % 2 != 0) {
                even = false;
                break;
            }
        }
        if (even) return true;

        sort(nums1.begin(), nums1.end());
        int prev = -1, curr = -1;
        for (int i=0; i<nums1.size(); i++) {
            // encouter odd number
            if (nums1[i] % 2 != 0) {
                prev = curr;
                curr = i;
            }
            // encouter even number
            else {
                // if there exist no previous odd to subtract even number
                if (curr < 0 || curr >= nums1.size()) {
                    return false;
                }
            }
        }
        return true;
    }
};