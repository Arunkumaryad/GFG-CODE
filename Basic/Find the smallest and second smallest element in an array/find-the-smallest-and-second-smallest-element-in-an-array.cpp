//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<int> minAnd2ndMin(int a[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++) 
            cin >> a[i];

        vector<int> ans = minAnd2ndMin(a, n);
        if (ans[0] == -1)
            cout << -1 << endl;
        else 
            cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}
// } Driver Code Ends


vector<int> minAnd2ndMin(int a[], int n) {
    int mini = INT_MAX;
    int secondMini = INT_MAX;
    if(n == 1) {
        return {-1,-1};
    }
    for(int i=0;i<n;i++) {
        if(mini > a[i]) {
            secondMini = mini;
            mini = a[i];
        }
        if(secondMini > a[i] && mini < a[i]) {
            secondMini = a[i];
        }
    }
    if(mini == INT_MAX || secondMini == INT_MAX) {
        return {-1,-1};
    }
    return {mini,secondMini};
}