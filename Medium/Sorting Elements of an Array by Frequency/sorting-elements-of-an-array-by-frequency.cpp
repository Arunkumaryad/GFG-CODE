#include <iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
 
static bool compare(pair<int,int> a, pair<int,int> b){
   if(a.second != b.second) return (a.second > b.second);
   return (a<b);
}
 
int main() {
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++) {
            int num;
            cin>>num;
            mp[num]++;
        }
        
        vector<pair<int,int>> v(mp.begin(),mp.end());
        
        sort(v.begin(),v.end(),compare);
        
        for(int i=0;i<v.size();i++){
            while(v[i].second--) cout<<v[i].first<<" ";
        }
        cout<<endl;
    }
return 0;
}