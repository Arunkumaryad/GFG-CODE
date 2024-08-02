//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solveUsingRec(string s, string t, int i, int j) {
        //base case.
        if(i >= s.length()) {
            return t.length()-j;
        }
        if(j >= t.length()) {
            return s.length()-i;
        }
        int ans = 0;
        //cahr mathced.
        if(s[i] == t[j]) {
            ans = 0 + solveUsingRec(s,t,i+1,j+1);
        }
        else {
            int replace = 1 + solveUsingRec(s,t,i+1,j+1);
            int insert = 1 + solveUsingRec(s,t,i,j+1);
            int del = 1 + solveUsingRec(s,t,i+1,j);
            ans = min(replace,min(insert,del));
        }
        return ans;
    }
    
    int solveUsingMem(string s, string t, int i, int j,vector<vector<int>>&dp) {
        //base case.
        if(i >= s.length()) {
            return t.length()-j;
        }
        if(j >= t.length()) {
            return s.length()-i;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        //cahr mathced.
        if(s[i] == t[j]) {
            ans = 0 + solveUsingMem(s,t,i+1,j+1,dp);
        }
        else {
            int replace = 1 + solveUsingMem(s,t,i+1,j+1,dp);
            int insert = 1 + solveUsingMem(s,t,i,j+1,dp);
            int del = 1 + solveUsingMem(s,t,i+1,j,dp);
            ans = min(replace,min(insert,del));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    int editDistance(string s, string t) {
        // Code here
        int i = 0;
        int j = 0;
        vector<vector<int>>dp(s.length()+1,vector<int>(t.length()+1,-1));
        int ans = solveUsingMem(s,t,i,j,dp);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends