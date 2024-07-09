//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int maxSortedAdjacentDiff(int* arr, int n) {
	    // code here
	    if(n<2) return 0;
	    
	    int maxEle = INT_MIN;
	   
	    for(int i=0;i<n;++i){
	        if(arr[i]>maxEle)
	        maxEle = arr[i];
	    }
	    int count[maxEle+1] = {0};
	    
	    for(int i=0;i<n;++i){
	        count[arr[i]]++;
	    }
	    vector<int>v;
	    for(int i=0;i<=maxEle;++i){
	        if(count[i]>0) v.push_back(i);
	    }
	    int len = v.size();
	    maxEle = INT_MIN;
	    for(int i=0;i<len-1;++i){
	        maxEle = max(maxEle,v[i+1]-v[i]);
	    }
	    return maxEle;
	}
};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxSortedAdjacentDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends