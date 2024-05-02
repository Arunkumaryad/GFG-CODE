//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isStrong(int N) {
        // code here
        int sum = 0;
        int num = N;
        while(num) {
            int digit = num%10;
            int fact = 1;
            for(int i=1;i<=digit;i++) {
                fact *= i;
            }
            sum += fact;
            num /= 10;
        }
        if(sum == N) {
            return true;
        }
        else{
            return false;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.isStrong(N) << endl;
    }
    return 0;
}
// } Driver Code Ends