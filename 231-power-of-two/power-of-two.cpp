class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0) return false;
        int cnt1 = 0, cnt0 = 0;
        while(n){
            int lastBit = n&1;
            if(lastBit==0) cnt0++;
            else cnt1++;
            n = n>>1;
        }
        if(cnt1==1) return true;
        return false;
    }
};