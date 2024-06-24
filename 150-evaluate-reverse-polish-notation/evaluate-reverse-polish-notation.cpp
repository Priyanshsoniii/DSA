class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int ans = 0;
        int len = tokens.size();
        for(int i=0;i<len;++i){
            if(tokens[i]=="*" || tokens[i]=="/" || tokens[i]=="-" || tokens[i]=="+"){
                int ele2 = stk.top();
                stk.pop();
                int ele1 = stk.top();
                stk.pop();
                cout<<ele1<<tokens[i]<<ele2<<endl;
                if(tokens[i]=="+") stk.push(ele1 + ele2);
                else if (tokens[i]=="-") stk.push(ele1 - ele2);
                else if (tokens[i]=="*") stk.push(ele1 * ele2);
                else if (tokens[i]=="/") stk.push(ele1 / ele2);
            }
            else{
                stk.push(stoi(tokens[i]));
            }
        }
        return stk.top();
    }
};