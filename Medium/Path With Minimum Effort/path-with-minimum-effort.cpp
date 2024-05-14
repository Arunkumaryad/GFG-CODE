//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
   bool isSafe(int newX, int newY, int row, int col, vector<vector<int>>& diff,int currX, int currY) {
        if(newX >= 0 && newY >= 0 && newX < row && newY < col && diff[currX][currY] < diff[newX][newY] ) {
            return true;
        }
        else {
            return false;
        }
    }
    int MinimumEffort(int row, int col, vector<vector<int>> &heights) {
        // code here
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> mini;
        vector<vector<int>>diff(row,vector<int>(col,INT_MAX));
        int destX = row - 1;
        int destY = col - 1;
        diff[0][0] = 0;
        mini.push({0,{0,0}});
        while(!mini.empty()) {
            auto topPair = mini.top();
            mini.pop();
            int currDiff = topPair.first;
            pair<int,int> currNodeIndexPair = topPair.second;
            int currX = currNodeIndexPair.first;
            int currY = currNodeIndexPair.second;
            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};
            for(int i=0;i<4;i++) {
                int newX = currX + dx[i];
                int newY = currY + dy[i];
                if(isSafe(newX, newY, row, col, diff, currX, currY)) {
                    int maxDiff = max(currDiff,abs(heights[currX][currY] - heights[newX][newY]));
                    diff[newX][newY] = min(diff[newX][newY],maxDiff);
                    if(newX != destX || newY != destY) {
                        mini.push({diff[newX][newY],{newX,newY}});
                    }
                }
            }
        }
        return diff[destX][destY];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends