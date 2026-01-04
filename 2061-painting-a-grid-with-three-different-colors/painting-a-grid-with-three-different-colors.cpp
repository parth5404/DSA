class Solution {
private:
    vector<string> strs;
    char arr[3] = {'R', 'G', 'B'};
    int MOD = 1e9 + 7;

public:
    vector<vector<int>> dp;

    void makeState(int n, string prev) {
        if (n == 0) {
            strs.push_back(prev);
            return;
        }
        for (int j = 0; j < 3; j++) {
            if (prev.back() != arr[j]) {
                makeState(n - 1, prev + arr[j]);
            }
        }
    }

    int solve(int col, int prev) {
        if (col == 0)
            return 1;

        if (dp[col][prev] != -1)
            return dp[col][prev];

        string &curr = strs[prev];
        long long res = 0;

        for (int i = 0; i < strs.size(); i++) {
            bool valid = true;
            for (int j = 0; j < curr.size(); j++) {
                if (strs[i][j] == curr[j]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                res = (res + solve(col - 1, i)) % MOD;
            }
        }

        return dp[col][prev] = res;
    }

    int colorTheGrid(int m, int n) {
        strs.clear();

        for (int i = 0; i < 3; i++) {
            string s(1, arr[i]);
            makeState(m - 1, s);
        }

        dp.assign(n, vector<int>(strs.size(), -1));

        long long ans = 0;
        for (int i = 0; i < strs.size(); i++) {
            ans = (ans + solve(n - 1, i)) % MOD;
        }

        return ans;
    }
};
