//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int firstElement(int n) {
        // code here
        int mod = 1e9+7;
        int first = 1;
        int second = 1;
        //base case .
        if(n == 1 || n == 2) {
            return 1;
        }
        for(int i=2;i<n;i++) {
            int temp = (first+second) % mod;
            first = second;
            second = temp;
        }
        return second;
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
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends