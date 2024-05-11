//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<long long>ans;
    vector<long long> jugglerSequence(long long n) {
        // code here
        ans.push_back(n);
        if(n == 1) {
            return ans;
        }
        if(n%2 == 0) {
            n = floor(pow(n,0.5));
        }
        else{
            n = floor(pow(n,1.5));
        }
        return jugglerSequence(n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        Solution ob;
        vector<long long> ans = ob.jugglerSequence(n);
        for (long long u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends