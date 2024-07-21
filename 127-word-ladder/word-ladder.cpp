class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st;
        for(auto it : wordList){
            st.insert(it);
        }
        int n = beginWord.size();
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            string curWord = q.front().first;
            int curCnt = q.front().second;
            st.erase(curWord);
            q.pop();
            if(curWord==endWord) return curCnt;
            for(int i=0;i<n;++i){
                string temp = curWord;
                for(char j = 'a'; j<='z';++j){
                    temp[i]=j;
                    if(st.find(temp)!=st.end()) q.push({temp,curCnt+1});
                }
            }
        }
        return 0;
    }
};