//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    const int mod = 1e9+7;
    int solveUsingMem(string&s1, string&s2, int i, int j, vector<vector<int>>& dp) {
        if(i>s1.size()) {
            return 0;
        }
        if(j >= s2.size()) {
            return 1;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans1 = 0;
        if(s1[i] == s2[j]) {
            ans1 = solveUsingMem(s1,s2,i+1,j+1,dp)%mod;
        }
        int ans2 = solveUsingMem(s1,s2,i+1,j,dp)%mod;
        dp[i][j] = (ans1+ans2)%mod;
        return dp[i][j];
    }
    int solveUsingRec(string&s1, string&s2, int i, int j) {
        //base case
        if(i>s1.size()) {
            return 0;
        }
        if(j >= s2.size()) {
            return 1;
        }
        int ans1 = 0;
        if(s1[i] == s2[j]) {
            ans1 = solveUsingRec(s1,s2,i+1,j+1)%mod;
        }
        int ans2 = solveUsingRec(s1,s2,i+1,j)%mod;
        int ans = (ans1+ans2)%mod;
        return ans % mod;
    }
    int countWays(string s1, string s2) {
        // code here
        int i = 0;
        int j = 0;
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
        int ans = solveUsingMem(s1,s2,i,j,dp);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends