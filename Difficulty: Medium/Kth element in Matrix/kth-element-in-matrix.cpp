//{ Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}

// } Driver Code Ends



int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
//   map<pair<int,int>,bool>vis;
//   int i=0,j=0;
//   int dirx[] = {-1,0,1,0,1,-1,-1,1};
//   int diry[] = {0,-1,0,1,1,-1,1,-1};
//   while(--k){
//       vis[{i,j}] = true;
//       int minVal = 20000;
//       int tempI=-1,tempJ=-1;
//       for(int d=0;d<8;++d){
//           int curX = i+dirx[d];
//           int curY = j+diry[d];
//           if(curX>=0 && curY>=0 && curX<n && curY<n && !vis[{curX,curY}]){
//               if(mat[curX][curY]<minVal){
//                  // cout<<mat[curX][curY]<<endl;
//                   minVal = mat[curX][curY];
//                   tempI = curX;
//                   tempJ = curY;
//                   vis[{curX,curY}] = true;
//               }
//           }
//       }
//       if(tempI!=-1 && tempJ!=-1){
//               i = tempI;
//               j = tempJ;
//         }
//   }
//   return mat[i][j];
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
if(k==1)
return mat[0][0];
k--;
vector<vector<int>> vis(n,vector<int>(n,0));
pq.push({mat[0][0],{0,0}});
vis[0][0]=1;
while(k--)
{
    auto it=pq.top();
    pq.pop();
    int i=it.second.first,j=it.second.second;
    if(i+1<n and !vis[i+1][j])
    {
        pq.push({mat[i+1][j],{i+1,j}});
        vis[i+1][j]=1;
    }
    if(j+1<n and !vis[i][j+1])
    {
         pq.push({mat[i][j+1],{i,j+1}});
         vis[i][j+1]=1;
    }
}
return pq.top().first;

   
}
