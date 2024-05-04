//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isPerfect(int N) {
        // code here
        int num = N;
        int sum = 0;
        while(num) {
            int digit = num % 10;
            int fact = 1;
            for(int i=1;i<=digit;i++) {
                fact *= i;
            }
            sum += fact;
            num /= 10;
        }
        if(sum == N) {
            return 1;
        }
        else {
            return 0;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isPerfect(N) << "\n";
    }
}

// } Driver Code Ends