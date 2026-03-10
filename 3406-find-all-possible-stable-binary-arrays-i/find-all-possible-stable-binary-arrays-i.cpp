class Solution {
public:
    int mod = 1e9 + 7;
    int dp[202][202][2];
    int solve(int zero, int one, int lt, int prev) {
        if (zero == 0 && one == 0) {
            return 1;
        }
        if (dp[zero][one][prev] != -1) {
            return dp[zero][one][prev];
        }
        int ans = 0;
        for (int i = 1; i <= min(lt, (prev == 1) ? zero : one); i++) {
            int val1 = zero;
            int val2 = one;
            if (prev == 1) {
                val1 = val1 - i;
            } else {
                val2 = val2 - i;
            }
            ans = (ans + solve(val1, val2, lt, (prev == 1) ? 0 : 1)) % mod;
        }
        return dp[zero][one][prev] = (ans) % mod;
    }
    int numberOfStableArrays(int zero, int one, int lt) {
        memset(dp,-1,sizeof(dp));
        return (solve(zero, one, lt, 0) + solve(zero, one, lt, 1)) % mod;
    }
};