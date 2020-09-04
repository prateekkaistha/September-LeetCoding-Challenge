class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int length = s.length();

        for(int div=2;length>=2;div++){
         if(s.length()%div==0){
             
             length = s.length()/div;
             string s1 = s.substr(0,length);
             string s2 = s.substr(length,length);
           
             bool check=true;
             for(int j=0;j<div;j++)
                    check = check && s1==s.substr(length*j,length);

             if(check)
                 return true;
         }    
        }
        return false;
    }
};
