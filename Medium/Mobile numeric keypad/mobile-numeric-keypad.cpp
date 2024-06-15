//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long int solve(long long num,long long n,map <long long, vector <long long>> &mp,vector<vector<long long>> &dp)
   {
       if(n==1)
       {
           return 1;
       }
      if(dp[num][n]!=-1)
      {
          return dp[num][n];
      }
      long long res=0;
      res+=solve(num,n-1,mp,dp);
      for(auto &it: mp[num])
      {
               res+=solve(it,n-1,mp,dp);
       }
       return dp[num][n]=res;
   }
    long long getCount(int n) {
        // Your code goes here
        map <long long, vector <long long>> mp;
        vector<vector<long long >> dp(10,vector<long long > (n+1,-1));
        mp[1] = {2,4};
        mp[2] = {1,3,5};
        mp[3] = {2,6};
        mp[4] = {1,5,7};
        mp[5] = {2,4,6,8};
        mp[6] = {3,5,9};
        mp[7] = {8,4};
        mp[8] = {7,5,9,0};
        mp[9] = {6,8};
        mp[0] = {8};
        long long ans=0;
        for(int i=0;i<10;i++)
        {
            ans+=solve(i,n,mp,dp);
        }
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

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends