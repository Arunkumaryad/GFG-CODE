//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int solveUsingMem(int n,int x, int y, int z, vector<int>& dp) {
        //base case
        if(n == 0) {
            return 0;
        }
        if(n < 0) {
            return INT_MIN;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        int ans1 = 1 + solveUsingMem(n-x,x,y,z,dp);
        int ans2 = 1 + solveUsingMem(n-y,x,y,z,dp);
        int ans3 = 1 + solveUsingMem(n-z,x,y,z,dp);
        dp[n] = max(ans1,max(ans2,ans3));
        return dp[n];
    }
    int solveUsingRec(int n, int x, int y, int z) {
        //base case
        if(n == 0) {
            return 0;
        }
        if(n < 0) {
            return INT_MIN;
        }
        int ans1 = 1 + solveUsingRec(n-x,x,y,z);
        int ans2 = 1 + solveUsingRec(n-y,x,y,z);
        int ans3 = 1 + solveUsingRec(n-z,x,y,z);
        int ans = max(ans1,max(ans2,ans3));
        return ans;
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int>dp(n+1,-1);
        int ans = solveUsingMem(n,x,y,z,dp);
        if(ans < 0) {
            return 0;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends