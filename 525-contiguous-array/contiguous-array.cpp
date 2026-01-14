class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> hash;
        hash[0] = -1;

        int sum = 0;
        int ans = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == 0) sum += -1;
            else              sum += 1;

            // put value into hash table and update the answer
            auto it = hash.find(sum);
            if (it != hash.end()) {
                ans = max(ans, (i - it->second) );
            }
            else {
                hash[sum] = i;
            }
        }
        return ans;
    }
};