//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void solve(stack<int>&st, int size, int cnt) {
        //base case
        if(cnt == size/2) {
            st.pop();
            return;
        }
        int temp = st.top();
        st.pop();
        solve(st,size,cnt+1);
        st.push(temp);
    }
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        int cnt = 0;
        solve(s,sizeOfStack,cnt);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends