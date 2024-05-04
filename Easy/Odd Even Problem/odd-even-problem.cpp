//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    string oddEven(string S) {
        // code here
        map<char,int> mp;
        for(char i:S){
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
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.oddEven(S) << endl;
    }
    return 0;
}

// } Driver Code Ends