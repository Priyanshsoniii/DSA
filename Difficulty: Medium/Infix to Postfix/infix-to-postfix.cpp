//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        // Your code here
        stack<char>stk;
        string postFix = "";
        int len = s.size();
        for(int i=0;i<len;++i){
            if((s[i] <= 'z' && s[i] >= 'a')||(s[i]<='Z' && s[i]>='A') || (s[i]>='0' && s[i]<='9')){
                postFix += s[i];
            }
            else if(s[i]=='^'){
                while(!stk.empty()){
                    if(stk.top()=='^'){
                        postFix += stk.top();
                        stk.pop();
                    }
                    else break;
                }
                stk.push(s[i]);
            }
            else if(s[i]=='(') stk.push(s[i]);
            else if(s[i]==')'){
                while(!stk.empty() && stk.top()!='('){
                    postFix += stk.top();
                    stk.pop();
                }
                stk.pop();
            }
            else if(s[i]=='+' || s[i]=='-'){
                while(!stk.empty()){
                    if(stk.top()=='^' || stk.top()=='+' || stk.top()=='-' || stk.top()=='*' || stk.top()=='/'){
                        postFix += stk.top();
                        stk.pop();
                    }
                    else break;
                }
                stk.push(s[i]);
            }
            else if(s[i]=='*' || s[i]=='/'){
                while(!stk.empty()){
                    if(stk.top()=='^' || stk.top()=='*' || stk.top()=='/'){
                        postFix += stk.top();
                        stk.pop();
                    }
                    else break;
                }
                stk.push(s[i]);
            }
        }
        
        while(!stk.empty()){
            postFix += stk.top();
            stk.pop();
        }
        
        return postFix;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends