//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isDigitSumPalindrome(int n) {
        // code here
        int num = n;
        int sum = 0;
        int rev = 0;
        while(num) {
            int digit = num%10;
            sum += digit;
            num /= 10;
        }
        int total = sum;
        while(sum) {
            int digit = sum %10;
            rev = rev*10 + digit;
            sum /= 10;
        }
        if(rev == total) {
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
        cout << ob.isDigitSumPalindrome(N) << "\n";
    }
}

// } Driver Code Ends