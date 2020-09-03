class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        string str;
        sort(A.begin(),A.end());
        vector<pair<int,int>> hoursIN;
        //hh starting with 2
        int hstart=-1;
        for(int i=3;i>=0;i--){
            if(A[i]<=2)
            {
                hstart=i;
                break;
            }
        }
        for(int i=hstart;i>=0;i--){
            for(int j=3;j>=0;j--){
                if(i!=j){
                    if(A[i]<2)
                        hoursIN.push_back(make_pair(i,j));
                    else{
                        if(A[j]<4)
                            hoursIN.push_back(make_pair(i,j));
                    }
                }
            }
        }
        
        for(int i=0;i<hoursIN.size();i++)
            cout<<A[hoursIN[i].first]<<A[hoursIN[i].second]<<endl;
      
        
        if(hoursIN.size()==0)
            return "";
        
        for(int i=0;i<hoursIN.size();i++){
            int sec[2];
            int index=0;
            for(int j=0;j<4;j++)
            {
                if(j!=hoursIN[i].first && j!=hoursIN[i].second)
                {
                    sec[index] = j;
                    index++;
                    if(index==2)
                        break;
                }
            }
        cout<<"For "<<hoursIN[i].first<<" and "<<hoursIN[i].second<<" values are : "<<sec[0]<<" "<<sec[1]<<endl;
         int mm1 = A[sec[0]]*10+A[sec[1]];
         int mm2 = A[sec[1]]*10+A[sec[0]];
         int mm=-1;
         if(mm1<59 && mm2<59)
             mm = max(mm1,mm2);
        else if(mm1<59 || mm2<59)
            mm = min(mm1,mm2);
        if(mm!=-1){
            str.append(to_string(A[hoursIN[i].first]));
            str.append(to_string(A[hoursIN[i].second]));
            str.append(":");
            if(mm<10)
                str.append("0");
            str.append(to_string(mm));
            return str;
            }
        }
        
        return "";
        return str;
    }
};
