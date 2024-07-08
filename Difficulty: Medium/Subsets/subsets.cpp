//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void solve(vector<int>&arr,vector<int>temp,vector<vector<int>>&res,int index,int n){
        if(index>=n){
                res.push_back(temp);
                temp.clear();
            return;
        }
        temp.push_back(arr[index]);
        solve(arr,temp,res,index+1,n);
        temp.pop_back();
        solve(arr,temp,res,index+1,n);
    }
    vector<vector<int> > subsets(vector<int>& a) {
        // code here
        vector<vector<int>>res;
        vector<int>temp;
        int n = a.size();
        solve(a,temp,res,0,n);
        sort(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n;

        vector<int> array;
        for (int i = 0; i < n; i++) {
            cin >> x;
            array.push_back(x);
        }

        Solution ob;
        vector<vector<int> > res = ob.subsets(array);

        // Print result
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++)
                cout << res[i][j] << " ";
            cout << endl;
        }
    }

    return 0;
}
// } Driver Code Ends