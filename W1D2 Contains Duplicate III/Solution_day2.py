class Solution:
    def containsNearbyAlmostDuplicate(self, n: List[int], k: int, t: int) -> bool:
        l=len(n)
        if t==0 and l==len(set(n)): return False
        else:
            for i in range(l):
                for j in range(i+1,min(l,i+1+k)):
                    if abs(n[i]-n[j])<=t:
                        return True
            return False