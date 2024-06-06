//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
        // Your code here
        long long sum = 0;
        for(int i=0;i<n;i++) {
            sum += a[i];
        }
        long long currSum = 0;
        for(int i=0;i<n;i++) {
            currSum += (long long)i*a[i];
        }
        long long maxSum = currSum;
        for(int i=1;i<n;i++) {
            currSum = currSum+sum-(long long)n*a[n-i];
            maxSum = max(maxSum,currSum);
        }
        return maxSum;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends