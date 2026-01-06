class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        table = {}
        for idx, n in enumerate(nums):
            # can compose with valid pair
            if target-n in table:
                return [idx, table[target-n]]
            # otherwise stroe in table
            else:
                table[n] = idx

        