class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        // start increasing
        int up = 0;
        while (up < n-1 && nums[up+1] > nums[up]) up++;
        if (up == 0 || up == n-1) return false;

        // start decreasing
        int down = up;
        while(down < n-1 && nums[down+1] < nums[down]) down++;
        if (down == up || down == n-1) return false;

        // another increasing
        int inc = down;
        while (inc < n-1 && nums[inc+1] > nums[inc]) inc++;
        return inc == n-1;
    }
};