class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long temp = x;
        long long revTemp = 0;
        while(temp){
            revTemp = 10*revTemp + temp%10;
            temp/=10;
        }
        temp = x;
        while(temp && revTemp){
            if(temp%10 != revTemp%10) return false;
            temp/=10;
            revTemp/=10;
        }
        return true;
    }
};