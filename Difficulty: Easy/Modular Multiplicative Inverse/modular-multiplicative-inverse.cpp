//{ Driver Code Starts
//Initial Template for C++

#include<iostream>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //Complete this function
    int modInverse(int a, int m)
    {
        //Your code here
        int limit = 10001;
        int cnt = 1;
        while(1){
            limit--;
            if(limit==0) break;
            if(((cnt*a)%m)==1) return cnt;
            cnt++;
        }
        cnt = -1;
        return cnt;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	
	//taking testcases
	cin>>T;
	while(T--){
		int a,m;
		
		//taking input a and m
		cin>>a>>m;
		Solution ob;
		//calling function modInverse()
		cout << ob.modInverse(a, m)<<endl;
	}
    return 0;
}
// } Driver Code Ends