//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void solve(vector<vector<int>> &m,int n, int i, int j,vector<string> &v, string temp){

        if(i<0 || i>=n || j<0 || j>=n || m[i][j]==0)

            return;

            

        if(i==n-1 && j==n-1){

            v.push_back(temp);

            return;

        }

        

        m[i][j] = 0;

        solve(m,n,i-1,j,v,temp+'U');

        solve(m,n,i+1,j,v,temp+'D');

        solve(m,n,i,j-1,v,temp+'L');

        solve(m,n,i,j+1,v,temp+'R');

        

        m[i][j] = 1;

        return;

        

    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        vector<string>v;
        int n = mat.size();
        solve(mat,n,0,0,v,"");
        return v;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends