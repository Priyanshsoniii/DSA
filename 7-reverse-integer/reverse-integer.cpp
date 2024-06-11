class Solution {
public:
    int reverse(int x) {
        bool isNeg = 0;
         long long int temp = x;
        if(temp<0){
            isNeg = 1;

            temp*=(-1);
        }

        long long int revNum=0;
        while(temp){
            if(revNum*10<=INT_MAX)
            revNum = 10*revNum + temp%10;
            else return 0;
            temp/=10;
        }

        if(isNeg){
            revNum*=(-1);
        } 
        return (revNum<INT_MIN || revNum>INT_MAX)?0:revNum; 
    }
};