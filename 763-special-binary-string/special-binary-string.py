class Solution:
    def makeLargestSpecial(self, s: str) -> str:
        # step 1. find balanced
        balanced = 0
        start = 0
        blocks = []
        for i in range(len(s)):
            balanced += 1 if s[i] == '1' else -1
            if balanced == 0:
                # step 2. recursively divide and conquer
                inner = self.makeLargestSpecial( s[start+1:i] )
                blocks.append( "1" + inner + "0" )
                start = i + 1
        # step 3. decreasing sort
        blocks.sort(reverse=True)
        # step 4. combine
        return ''.join(blocks)