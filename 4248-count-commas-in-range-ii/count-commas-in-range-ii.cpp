class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        if (n >= 1e3)
            ans += (min(n, (long long)1e6 - 1) - (long long)1e3 + 1) * 1;

        if (n >= 1e6)
            ans += (min(n, (long long)1e9 - 1) - (long long)1e6 + 1) * 2;

        if (n >= 1e9)
            ans += (min(n, (long long)1e12 - 1) - (long long)1e9 + 1) * 3;

        if (n >= 1e12)
            ans += (min(n, (long long)1e15 - 1) - (long long)1e12 + 1) * 4;

        if (n >= 1e15)
            ans += (n - (long long)1e15 + 1) * 5;

        return ans;
    }
};