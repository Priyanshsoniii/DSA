class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int len = arr.size();
        for(int i=2;i<len;++i){
            if(arr[i]%2!=0 && arr[i-1]%2!=0 && arr[i-2]%2!=0) return true;
        }
        return false;
    }
};