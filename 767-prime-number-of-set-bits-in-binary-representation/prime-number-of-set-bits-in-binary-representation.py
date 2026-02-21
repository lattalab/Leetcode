class Solution:
    def checkPrime(self, num):
        if num <= 1:
            return 0
        
        for i in range(2, int(num**0.5)+1, 1):
            if num % i == 0:
                return 0
        return 1

    def countPrimeSetBits(self, left: int, right: int) -> int:
        ans = 0

        for i in range(left, right+1):
            setBits = bin(i).count('1')
            if (self.checkPrime(setBits)):
                ans += 1
        
        return ans