class Solution {
public:
    int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    int solve(int n, int l, int r, int prev, bool isInc) {
        if (n == 0) {
            return 1;
        }
        if (dp[isInc][prev][n] != -1) {
            return dp[isInc][prev][n];
        }
        int ans = 0;
        if (!isInc) {
            for (int i = prev - 1; i >= l; i--) {
                ans = (ans + solve(n - 1, l, r, i, 1)) % MOD;
            }
        } else {
            for (int i = prev + 1; i <= r; i++) {
                ans = (ans + solve(n - 1, l, r, i, 0)) % MOD;
            }
        }
        return dp[isInc][prev][n] = ans % MOD;
    }
    int zigZagArrays(int n, int l, int r) {
        int ans = 0;
        // dp = vector<vector<vector<int>>>(
        //     2, vector<vector<int>>(r + 1, vector<int>(n + 1, -1)));
        // dp = vector<vector<vector<int>>>(
        //     n + 1, vector<vector<int>>(2, vector<int>(r - l + 1, 0)));
        // for (int i = l; i <= r; i++) {
        //     for (int j = l; j < i; j++) {
        //         ans = (ans + solve(n - 2, l, r, j, 1)) % MOD;
        //     }
        //     for (int k = i + 1; k <= r; k++) {
        //         ans = (ans + solve(n - 2, l, r, k, 0)) % MOD;
        //     }
        // }
        vector<int> prefup(r - l + 1, 1);
        vector<int> prefdwn(r - l + 1, 1);
        vector<int> dp1(r - l + 1, 1);
        vector<int> dp2(r - l + 1, 1);
        for (int i = 1; i < prefup.size(); i++) {
            prefup[i] = prefup[i] + prefup[i - 1];
            prefdwn[i] = prefdwn[i] + prefdwn[i - 1];
        }
        for (int i = 2; i <= n; i++) {
            for (int incr = 0; incr <= 1; incr++) {
                vector<int> pref;
                for (int k = 0; k < r - l + 1; k++) {
                    if (incr == 0) {
                        dp1[k] = (k - 1 >= 0) ? prefup[k - 1] : 0;
                    } else {
                        dp2[k] = (prefdwn.back() - prefdwn[k] + MOD) % MOD;
                    }
                }
            }
            prefdwn[0] = dp1[0];
            prefup[0] = dp2[0];
            for (int k = 1; k < r - l + 1; k++) {
                prefdwn[k] = (prefdwn[k - 1] + dp1[k]) % MOD;
                prefup[k] = (prefup[k - 1] + dp2[k]) % MOD;
            }
        }
        for (int k = 0; k < r - l + 1; k++) {
            ans = (ans + dp1[k]) % MOD;
            ans = (ans + dp2[k]) % MOD;
        }
        return (ans) % MOD;
    }
};