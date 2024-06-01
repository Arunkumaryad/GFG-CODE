//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        // code here
         map<char,int> mp;
        for(char i:s){
            mp[i]++;
        }
        
        int X=0,Y=0;
        for(auto i:mp){
            if(!((i.first-96) & 1) && !(i.second & 1)) X++;
            if((i.first-96 & 1) && (i.second & 1)) Y++;
        }
        
        if(X+Y & 1) return "ODD";
        
        return "EVEN";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends