class Solution {
public:
    string invert(string str){
        for(auto &x : str){
            if(x=='0') x = '1';
            else if(x=='1') x = '0';
        }
        return str;
    }
    string getStr(int i){
        if(i<=1) return "0";
        string str = getStr(i-1);
        string inv = invert(str);
        str += "1";
        string temp = str;
        reverse(inv.begin(),inv.end());
        temp += inv;
        return temp;
    }
    char findKthBit(int n, int k) {
        string s = getStr(n);
        return s[k-1];
    }
};