//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int mod = 1000000007;
    int minProduct(int arr[], int n, int k)
    {
        // Complete the function
        long long int ans = 1;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;++i){
            pq.push(arr[i]);
        }
        while(k--){
            ans = (ans%mod * pq.top())%mod;
            ans%=mod;
            pq.pop();
        }
        return ans%mod;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        cin>>k;
        Solution ob;
	    cout<<ob.minProduct(arr, n, k)<<endl;
    }
	return 0;
}

// } Driver Code Ends