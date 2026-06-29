class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        
        ans = 0
        
        def check(patterns: str, word: str):
            m = len(word)
            n = len(patterns)
            for start in range(0, m-n+1):
                flag = True
                for j in range(0, n):
                    if (word[start+j] != patterns[j]):
                        flag = False
                        break
                if flag:
                    return True
            return False

        for p in patterns:
            ans += check(p, word)
        
        return ans