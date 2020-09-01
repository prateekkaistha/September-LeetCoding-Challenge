class Solution:
    def largestTimeFromDigits(self, a: List[int]) -> str:
        t=''
        for i in range(4):
            for j in range(4):
                for k in range(4):
                    if i!=j and j!=k and k!=i:
                        hh=str(a[i])+str(a[j])
                        mm=str(a[k])+str(a[6-i-j-k])
                        _t=hh+':'+mm
                        if hh<'24' and mm<'60' and _t>t:
                            t=_t
        return t