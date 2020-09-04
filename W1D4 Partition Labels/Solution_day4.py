class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        n=len(s)
        f=s[0]
        flag=0
        st,e=0,0
        pos=[]
        if n==1:
            return [n]
        while(e<n-1):
            e=s.rfind(f)
            while e==st and e<n: #single alphabet
                pos.append(e)
                st=e+1
                if st>=n:
                    flag=1
                    break
                f=s[st]
                e=s.rfind(f)
            if flag==1: break
            temp_set=list(set(s[st+1:e]))
            if len(temp_set)!=0:
                temp_pos=[]
                for i in temp_set:
                    temp_pos.append(s.rfind(i))
                prev_e=e
                e=max(e,max(temp_pos))
                if e>prev_e: 
                    while len(set(s[st+1:e]))>len(set(s[st+1:prev_e])):
                        temp_pos=[]
                        for i in s[st+1:e]:
                            temp_pos.append(s.rfind(i))
                        prev_e=e
                        e=max(e,max(temp_pos))
            pos.append(e)
            st=e+1
            if e<n-1:
                f=s[st]
        for i in range(len(pos)-1,0,-1):
            pos[i]-=pos[i-1]
        pos[0]+=1
        return pos