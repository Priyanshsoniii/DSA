//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<long long> factorialNumbers(long long N)
    {
      vector<long long>ans;
      long long F=1,prevF=1;
      for(int i=1; ;++i){
            F = i*prevF;
            if(F<=N) ans.push_back(F);
            else return ans;
            prevF = F;
          
      }
      return {-1};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;
        cin>>N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for(auto num : ans){
            cout<<num<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}
// } Driver Code Ends