//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        string result = arr[0];
        int N = arr.size();
        for(int i = 1; i < N; i++){
           
            string r = arr[i];
            string s ="";
            
            for(int j = 0; j < r.size(); j++){
                if(result[j] == r[j]){
                    s += result[j];
                }else{
                    break;
                }
            }
            result = s;
        }
        if(result == ""){
            result ="-1";
        }
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends