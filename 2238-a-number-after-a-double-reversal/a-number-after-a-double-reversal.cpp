class Solution {
public:
    bool isSameAfterReversals(int num) {
        int temp = num;
        int rev1 = 0;
        while(temp){
            rev1 = rev1*10 + temp%10;
            temp/=10;
        }

        temp = rev1;
        int rev2 = 0;
        while(temp){
            rev2 = rev2*10 + temp%10;
            temp/=10;
        }

        cout<<num<<" "<<rev1<<" "<<rev2<<endl;
        if(rev2 == num) return true;
        return false;
    }
};