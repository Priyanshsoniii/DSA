class Solution {
public:
    bool isPalindrome(string s) {
        string s2 = "";
        int len = s.size();
        for(int i=0;i<len;++i){
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9')){
                s2+=s[i];
            }
        }
        transform(s2.begin(),s2.end(),s2.begin(),::tolower);
        string temp = s2;
        reverse(temp.begin(),temp.end());
        int i=0;
        int len2 = temp.size();
        while(i<len2){
            if(temp[i]!=s2[i]) return 0;
            i++;
        }

        return 1;
    }
};