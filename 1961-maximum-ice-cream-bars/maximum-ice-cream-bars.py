class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        # 1. finding the maximum
        max_val = max(costs)
        # 2. create frequency list
        cnt = [0] * (max_val + 1)
        # 3. count the frequency
        for num in costs: 
            cnt[num] += 1
        # 4. try to get cheapest item from the frequency info
        ans = 0
        for price in range(1, max_val+1):
            
            # can not buy anymore (the more iteration the more expansive)
            if price > coins:
                break

            if cnt[price] == 0:
                continue
            
            # how many can buy at this price
            # when the supplies can only offer small amount, choose this
            can_buy = min(cnt[price], coins // price)

            coins -= can_buy * price
            ans += can_buy
        
        return ans