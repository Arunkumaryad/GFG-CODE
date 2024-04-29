//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int solve(int *arr, int index, int n) {
	    //base case
	    if(index >= n) {
	        return 0;
	    }
	    //chori krlo.
	    int ans1 = arr[index]+solve(arr,index+2,n);
	    //chori na kro.
	    int ans2 = 0 + solve(arr,index+1,n);
	    int ans = max(ans1,ans2);
	    return ans;
	}
	int solve2(int *arr, int index, int n, vector<int>& dp) {
	    //base case.
	    if(index >= n) {
	        return 0;
	    }
	    if(dp[index] != -1) {
	        return dp[index];
	    }
	    //chori krlo.
	    int ans1 = arr[index] + solve2(arr,index+2,n,dp);
	    int ans2 = 0 + solve2(arr,index+1,n,dp);
	    dp[index] = max(ans1,ans2);
	    return dp[index];
	}
	int findMaxSum(int *arr, int n) {
	    // code here
	    int index = 0;
	    vector<int>dp(n+1,-1);
	    int ans = solve2(arr,index,n,dp);
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends