class Solution {
public:
    int concatenatedBinary(int n) {
        long long res = 0;
        int mod = 1e9 + 7;
        for (int i = 1; i <= n; i++) {
            long long bits = log2(i) + 1;
            res = ((res << bits) % mod + i) % mod;
        }
        return res;
    }
};