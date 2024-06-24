//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct node {
    string data;
    struct node *left;
    struct node *right;

    node(string x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

bool isExpression(string &s) {
    if (s == "+" or s == "-" or s == "*" or s == "/") return true;
    return false;
}



// } Driver Code Ends
/*The structure of node is as follows
struct node{
    string data;
    node *left;
    node *right;
};
*/

class Solution{
  public:
    /*You are required to complete below method */
    bool isOperator(string op){
        if(op=="*" || op=="-" || op=="/" || op=="+") return true;
        return false;
    }
    
    int toInt(string str){
        int ans = 0;
        reverse(str.begin(),str.end());
        while(!str.empty()){
            ans = ans*10 + str.back()-'0';
            str.pop_back();
        }
        //cout<<ans<<endl;
        return ans;
    }
    
    int solve(node*root){
        if(isOperator(root->data)){
          //  cout<<root->data<<endl;
            if(root->data=="-") return (solve(root->left)  - solve(root->right));
            else if(root->data=="+") return (solve(root->left) + solve(root->right));
            else if(root->data=="/") return (solve(root->left) / solve(root->right));
            else if(root->data=="*") return (solve(root->left) * solve(root->right));
        }
        else if(root!=NULL && root->left==NULL && root->right== NULL){
            //cout<<toInt(root->data)<<endl;
            return toInt(root->data);
        } 
    }
    int evalTree(node* root) {
        // Your code here
        return solve(root);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s[n];
        for (int i = 0; i < n; i++) cin >> s[i];

        int p = 0;
        node *root = new node(s[p++]);
        queue<node *> q;
        q.push(root);
        while (!q.empty()) {
            node *f = q.front();
            q.pop();
            node *l, *r;
            if (isExpression(f->data)) {
                l = new node(s[p++]);
                r = new node(s[p++]);
                f->left = l;
                f->right = r;
                q.push(l);
                q.push(r);
            }
        }
        Solution obj;
        cout << obj.evalTree(root) << endl;
    }
}

// } Driver Code Ends