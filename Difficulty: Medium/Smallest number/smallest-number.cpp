//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
        if(s > 9*d) return "-1";
        string ans = "";
        int i=0;
        while(i++ < d) ans.push_back(' ');
        for(int i=d-1;i>=0;i--)
        {
            if(s-1 >= 9)
            {
                ans[i] = '9';
                s-=9;
            }
            else
            {
                if(i!=0)
                {
                    char num = (s-1) + '0';
                    ans[i] = num;
                    s -= (s-1);
                    while(i!=0)
                    {
                        ans[--i] = '0';
                    }
                }
                ans[0] = s + '0';
                
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends