class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        x=s in (s+s)[1:-1]
        return x