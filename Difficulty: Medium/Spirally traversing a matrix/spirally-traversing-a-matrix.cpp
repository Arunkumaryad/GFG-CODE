//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int>ans;
        int cnt=0;
        int total=r*c;
        int startingRow=0;
        int startingCol=0;
        int endingRow=r-1;
        int endingCol=c-1;
        while(cnt < total)
        {
            for(int i=startingCol;cnt<total && i<=endingCol;i++)
            {
                ans.push_back(matrix[startingRow][i]);
                cnt++;
            }
            startingRow++;
            
            //For end col.
            for(int i=startingRow;cnt<total && i<=endingRow;i++)
            {
                ans.push_back(matrix[i][endingCol]);
                cnt++;
            }
            endingCol--;
            
            //For ending Row.
            for(int i=endingCol;cnt<total && i>=startingCol;i--)
            {
                ans.push_back(matrix[endingRow][i]);
                cnt++;
            }
            endingRow--;
            
            //For traversing first columns.
            for(int i=endingRow;cnt<total && i>=startingRow;i--)
            {
                ans.push_back(matrix[i][startingCol]);
                cnt++;
            }
            startingCol++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends