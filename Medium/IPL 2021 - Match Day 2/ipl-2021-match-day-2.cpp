//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
          vector<int>ans;
        int maxi = INT_MIN;
        
        for(int i=0;i<k;i++){
            maxi = max(maxi,arr[i]);
        }
        ans.push_back(maxi);
        
        for(int i=1;i<=n-k;i++){
            if(maxi == arr[i-1]){
                maxi = INT_MIN;
                
                for(int j=i;j<i+k;j++){
                    maxi = max(maxi,arr[j]);
                }
            }
            else{
                maxi = max(maxi,arr[i+k-1]);
            }
            
            ans.push_back(maxi);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends