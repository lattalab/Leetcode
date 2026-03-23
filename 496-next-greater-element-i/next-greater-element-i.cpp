class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        stack<int> st;
        st.push(nums2[0]);
        for (int i=1; i<nums2.size(); i++) {
            if (st.top() >= nums2[i]) {
                st.push(nums2[i]);
            }
            else {
                while (!st.empty() && st.top() < nums2[i]) {
                    int val = st.top();
                    st.pop();
                    mp[val] = nums2[i];
                }
                st.push(nums2[i]);
            }
        }
        vector<int> result;
        for (int i=0; i<nums1.size(); i++) {
            if (mp.find(nums1[i]) != mp.end()) {
                result.push_back(mp[nums1[i]]);
            }
            else {
                result.push_back(-1);
            }
        }
        return result;
    }
};