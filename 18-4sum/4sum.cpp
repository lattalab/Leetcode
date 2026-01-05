class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); i++){

            // redundant
            if (i>0 && nums[i] == nums[i-1])
                continue;

            for (int j=i+1; j<nums.size(); j++){

                // remove redundant
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                int left = j+1;
                int right = nums.size() - 1;
                // 2 pointers
                while (left < right){
                    long long int temp_sum = (long long int) nums[i] + nums[j] + nums[left] + nums[right];
                    if (temp_sum < target) left++;
                    else if (temp_sum > target) right--;
                    else {
                        result.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});

                        // remove redundant
                        while(right > left && nums[left] == nums[left+1]) left++;
                        while(right > left && nums[right] == nums[right-1]) right--;

                        left++;
                        right--;
                    }
                }   // END while
            }   // END for
        }
        return result;
    }
};