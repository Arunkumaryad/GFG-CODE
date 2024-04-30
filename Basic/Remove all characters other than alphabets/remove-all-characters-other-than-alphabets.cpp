//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
    string removeSpecialCharacter(string s) {
        // code here
        string ans = "";
        for(int i=0;i<s.size();i++) {
            if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
                ans += s[i];
            }
        }
        if(ans.size() > 0) {
            return ans;
        }
        else{
            return "-1";
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.removeSpecialCharacter(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends