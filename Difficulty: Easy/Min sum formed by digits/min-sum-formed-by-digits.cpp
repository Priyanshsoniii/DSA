//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        // Your code goes here
        priority_queue<long long int,vector<long long int>,greater<long long int>>pq;
        for(int i=0;i<n;++i) pq.push(arr[i]);
        int i=0,len = pq.size();
        long long int num1 = 0,num2=0,temp=0;
        while(i<len){
            if(i<len){
              temp = pq.top();
              pq.pop();
              i++;
              num1 = num1*10 + temp;
            }
            if(i<len){
              temp = pq.top();
              pq.pop();
              i++;
              num2 = num2*10 + temp;
            }
        }
        return num1+num2;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends