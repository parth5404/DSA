class Solution {
    public int[][] dp;

    public int solve(int[] prices, boolean sell, int i) {
        if (i == prices.length) return 0;

        if (dp[i][sell ? 1 : 0] != Integer.MIN_VALUE)
            return dp[i][sell ? 1 : 0];

        int ret;
        if (!sell) {
            ret = -prices[i] + solve(prices, true, i + 1);
        } else {
            ret = prices[i] + solve(prices, false, i + 1);
        }

        int profit = solve(prices, sell, i + 1);

        return dp[i][sell ? 1 : 0] = Math.max(ret, profit);
    }

    public int maxProfit(int[] prices) {
        dp = new int[prices.length][2];
        for (int i = 0; i < prices.length; i++) {
            dp[i][0] = dp[i][1] = Integer.MIN_VALUE;
        }
        return solve(prices, false, 0);
    }
}
