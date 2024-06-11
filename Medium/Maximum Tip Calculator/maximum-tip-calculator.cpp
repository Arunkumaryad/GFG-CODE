//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        // code here
        vector<pair<int,int>> s;
        for(int i=0;i<n;i++)
        {
            int diff=abs(arr[i]-brr[i]);
            s.push_back({diff,i});
        }
        sort(s.begin(),s.end());
        long long ans=0;
        int i=n-1;
        while(x>0 && y>0 && i>=0)
        {   
            if(arr[s[i].second]>brr[s[i].second])
            {
                ans+=arr[s[i].second];
                x--;
            }
            else if(arr[s[i].second]<brr[s[i].second])
            {
                ans+=brr[s[i].second];
                y--;
            }
            else
            {
                if(x>y)
                {
                    ans+=arr[s[i].second];
                    x--;
                }
                else
                {
                    ans+=brr[s[i].second];
                    y--;
                }
            }
            i--;
        }
        if(y==0)
        {   
            
            while(x>0 && i>=0)
            {   
                
                ans+=arr[s[i].second];
                x--;
                i--;
            }
        }
        else if(x==0)
        {
            while(y>0 && i>=0)
            {
                
                ans+=brr[s[i].second];
                y--;
                i--;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends