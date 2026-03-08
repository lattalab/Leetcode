class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        // hash table
        unordered_set<int> st;
        for (int i=0; i<nums.size(); i++) {
            st.insert(stoi(nums[i], nullptr, 2));
        }

        for (int i=0; i<(1 << n); i++) {
            if (st.find(i) == st.end()) {
                string s = bitset<16>(i).to_string();
                // fetch last n bits
                return s.substr(16 - n);;
            }
        }
        return "";
    }
};