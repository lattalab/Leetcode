class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        loop = True
        for i in range(len(letters)):
            if ord(letters[i]) > ord(target):
                return letters[i]
        if loop:
            return letters[0]