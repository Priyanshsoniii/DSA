//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long gcd(long long A,long long B){
         return A%B==0?B:gcd(B,A%B);
    }
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        if(A<B){
            long long temp = A;
            A = B;
            B = temp;
        }
        long long GCD = gcd(A,B);
        return {(A*B)/GCD,GCD};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends