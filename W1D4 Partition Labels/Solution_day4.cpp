class Solution {
public:
    vector<int> partitionLabels(string S) {
        map<char,pair<int,int>> store;
        for(int i=0;i<S.length();i++){
            if(store.find(S[i])!=store.end()){
                store[S[i]].second = i;
            }
            else{
                store[S[i]] = make_pair(i,i);
            }
        }
        
        vector<int> ans;
        for(auto itr=store.begin();itr!=store.end();itr++){
            cout<<itr->first<<" "<<itr->second.first<<" : "<<itr->second.second<<endl;
        }
        int k=0;
        int start=0;
        int divisions=0;
        for(int i=0;i<S.length();i++){
            if(store[S[i]].first<=k){
                if(store[S[i]].second>k){
                    k=store[S[i]].second;
                }
            }
            else if(store[S[i]].first>k){
                cout<<"Start : "<<start<<" end : "<<k<<endl;
                ans.push_back(k-start+1);
                divisions++;
                k=store[S[i]].second;
                start=store[S[i]].first;
            }
                
        }
        cout<<"Start : "<<start<<" end : "<<k<<endl;
          ans.push_back(k-start+1);
              
        cout<<divisions<<endl;
        return ans;
    }
};
