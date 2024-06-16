//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
     bool isPrime(int n)
   {
       if(n<=1)return 0;
       for(int i=2;i<=sqrt(n);i++)
       if(n%i==0)return 0;
       return 1;
   }
    vector<int> getPrimes(int N) {
        // code here
         vector<int> vec;
       for(int i=1;i<=N/2;i++)
       {
           if(isPrime(i) && isPrime(N-i))
           {
               vec.push_back(i);
               vec.push_back(N-i);
               return vec;
           }     
       }
       vec.push_back(-1);
       vec.push_back(-1);
       return vec;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends