//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool solve(vector<int>&arr,int index,int sum,vector<vector<int>>&dp){
        if(sum==0) return true;
        if(index<0 || sum<0) return false;
        if(dp[index][sum]!=-1) return dp[index][sum];
        
        bool pick = solve(arr,index-1,sum-arr[index],dp);
        
        bool notPick = solve(arr,index-1,sum,dp);
        return dp[index][sum]= notPick|pick;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(arr,n-1,sum,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends