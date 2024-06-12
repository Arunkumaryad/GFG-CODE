//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int n) {
        string str = to_string(n);
        int found = str.find("4");
        if(found != -1) {
            return 1;
        }
        return 0;
    }
    int countNumberswith4(int n) {
        // code here
        int cnt = 0;
        for(int i=1;i<=n;i++) {
            if(solve(i)) {
                cnt++;
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends