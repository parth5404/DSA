class Solution {
public:
    vector<vector<vector<long long>>> dp;
    long long solve(vector<int>& prices, int k, int idx, int CASE) {
        if (idx == prices.size()) {
            if (CASE != 0)
                return INT_MIN;
            return 0;
        }
        if (dp[idx][k][CASE] != INT_MIN) return dp[idx][k][CASE];
        long long notpick = solve(prices, k, idx + 1, CASE);
        long long pick = INT_MIN;
        if (k > 0) {
            if (CASE == 1) {
                long long fresh_sell =
                    prices[idx] + solve(prices, k - 1, idx + 1, 0);
                pick = fresh_sell;
            } else if (CASE == 2) {
                long long short_buy =
                    -prices[idx] + solve(prices, k - 1, idx + 1, 0);
                pick = short_buy;
            } else if (CASE == 0) {
                long long fresh_buy =
                    -prices[idx] + solve(prices, k, idx + 1, 1);
                long long short_sell =
                    prices[idx] + solve(prices, k, idx + 1, 2);
                pick = max(fresh_buy, short_sell);
            }
        }
        return dp[idx][k][CASE] = max(pick, notpick);
    }
    long long maximumProfit(vector<int>& prices, int k) {
        dp.assign(prices.size() + 2, vector<vector<long long>>(
                                         k + 2, vector<long long>(3, INT_MIN)));
        return solve(prices, k, 0, 0);
    }
};