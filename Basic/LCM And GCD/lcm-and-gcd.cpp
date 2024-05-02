//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    long long gcd(int a, int b) {
        if(a == 0) {
            return b;
        }
        if(b == 0) {
            return a;
        }
        while(a != b) {
            if(b > a) {
                b = b-a;
            }
            if(a > b) {
                a = a-b;
            }
        }
        return a;
    }
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        vector<long long>ans;
        //for lcm
        ans.push_back((A*B)/gcd(A,B));
        ans.push_back(gcd(A,B));
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends