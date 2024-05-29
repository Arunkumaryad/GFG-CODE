//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solveUsingMem(int n, int x, int y, vector<int>& dp) {
         //base case.
        if(n == 0) {
            return 0;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        int ans1 = 0;
        int ans2 = 0;
        int ans3 = 0;
        if(n >= x) {
            ans1 = 1+ solveUsingMem(n-x,x,y,dp);
        }
        if(n >= y) {
            ans2 = 1 + solveUsingMem(n-y,x,y,dp);
        }
        ans3 = 1 + solveUsingMem(n-1,x,y,dp);
        if(ans1%2 == 1 || ans2%2 == 1 || ans3%2 == 1) {
            return dp[n] = 1;
        }
        return dp[n] = 0;
    }
    int solveUsingRec(int n, int x, int y) {
        //base case.
        if(n == 0) {
            return 0;
        }
        int ans1 = 0;
        int ans2 = 0;
        int ans3 = 0;
        if(n >= x) {
            ans1 = 1+ solveUsingRec(n-x,x,y);
        }
        if(n >= y) {
            ans2 = 1 + solveUsingRec(n-y,x,y);
        }
        ans3 = 1 + solveUsingRec(n-1,x,y);
        if(ans1%2 == 1 || ans2%2 == 1 || ans3%2 == 1) {
            return 1;
        }
        return 0;
    }
    int findWinner(int n, int x, int y) {
        // code here
        vector<int>dp(n+1,-1);
        int ans = solveUsingMem(n,x,y,dp);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        Solution obj;
        int res = obj.findWinner(n, x, y);

        cout << res << endl;
    }
}

// } Driver Code Ends