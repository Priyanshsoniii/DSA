class Solution {
public:
    bool isValid(string s) {

        int len = s.size();
        if(len == 1) return false;
        stack<char>stk;
        char top = '0';
        for(int i=0;i<len;++i){
            if(!stk.empty())
             top = stk.top();
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') stk.push(s[i]);
            else if(s[i]==')'){
                if(top=='('){
                    if(stk.size()==0) return false;
                    stk.pop();
                } 
                else return false;
            }
            else if(s[i]=='}'){
                if(top=='{'){
                    if(stk.size()==0) return false;
                    stk.pop();
                }
                 else return false;
            }
            else if(s[i]==']'){
                if(top=='['){
                    if(stk.size()==0) return false;
                    stk.pop();
                }
                else return false;
            }
        }
        if(stk.size()>0) return false;
        return true;
    }
};