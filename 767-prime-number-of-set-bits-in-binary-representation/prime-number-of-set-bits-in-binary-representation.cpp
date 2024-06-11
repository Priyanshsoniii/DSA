class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int cnt=0;
        int n = right;
        bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    prime[1] = 0;
    for(int i=left;i<=right;++i){
        if(prime[__builtin_popcount(i)]) {
            cout<<i<<"->"<<__builtin_popcount(i)<<"->"<<prime[__builtin_popcount(i)]<<endl;
            cnt++;
        }
    }
    
    return cnt;
  }
};