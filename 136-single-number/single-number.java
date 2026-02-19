import java.util.*;

class Solution {
    public int singleNumber(int[] nums) {
        Set<Integer> set = new HashSet<>();
        int sumSet = 0;
        int sumNums = 0;

        // get unique value
        for (int num : nums) {
            if (!set.contains(num)) {
                set.add(num);
                sumSet += num;
            }
            // acculate sum
            sumNums += num;
        }

        // 2* (a1 + a2 + ... + ak + ak+1) - 2*(a1 + a2 +... + ak) + ak-1
        return 2 * sumSet - sumNums;
    }
}