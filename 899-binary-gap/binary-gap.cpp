class Solution {
public:
    int binaryGap(int n) {
        long long ans = 0;
        int prev = -1;
        int cnt = 0;
        while (n != 0) {
            if (n & 1) {
                if (prev == -1)
                    prev = cnt;
                else {
                    ans = max(ans*1LL, (cnt - prev)*1LL);
                    prev = cnt;
                }
            }
            cnt++;
            n = n / 2;
        }
        return ans;
    }
};