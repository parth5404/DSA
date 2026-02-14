class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(105, vector<double>(105, 0.0));
        dp[0][0] = poured;

        for (int i = 0; i <= query_row; i++) {
            for (int j = 0; j <= i; j++) {
                if (dp[i][j] > 1.0) {
                    double extra = dp[i][j] - 1.0;
                    dp[i][j] = 1.0;
                    dp[i+1][j] += extra / 2.0;
                    dp[i+1][j+1] += extra / 2.0;
                }
            }
        }

        return min(1.0, dp[query_row][query_glass]);
    }
};
