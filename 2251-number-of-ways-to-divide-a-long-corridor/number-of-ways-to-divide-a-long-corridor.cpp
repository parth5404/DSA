class Solution {
public:
    int numberOfWays(string corr) {
        int ways = 0;
        int seats = 0;
        const int mod=1e9+7;
        int ans = 1;
        for (int i = 0; i < corr.length(); i++) {
            if (corr[i] == 'S')
                seats++;
            if (seats == 2) {
                ways++;
            }
            if(seats==3){
                ans=(ans*1LL*ways)%mod;
                seats=1;
                ways=0;
            }
        }
        if(seats!=2)return 0;

        return ans;
    }
};