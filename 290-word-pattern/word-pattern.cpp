class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,int>vis;
        int size = pattern.size();
        string temp = "0";
        vis[pattern[0]] = 0;
        for(int i=1;i<size;++i){
            if(vis[pattern[i]]==0 && pattern[i] != pattern[0]){
                vis[pattern[i]] = i;
                temp += (i+'0');
            }
            else temp += (vis[pattern[i]]+'0');
        }
        cout<<temp<<endl;
    
        vector <string> tokens;
        stringstream check1(s);
        string intermediate;
        while(getline(check1, intermediate, ' '))
        {
            tokens.push_back(intermediate);
        }
        string temp2 = "0";

        unordered_map<string,int>vis2;
        int size2 = tokens.size();
        vis2[tokens[0]] = 0;
        for(int i=1;i<size2;++i){
            if(vis2[tokens[i]]==0 && tokens[i] != tokens[0]){
                vis2[tokens[i]] = i;
                temp2 += (i+'0');
            }
            else temp2 += (vis2[tokens[i]]+'0');
        }

        return (temp==temp2);
    }
};