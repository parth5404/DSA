class Solution {
public:
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i >= grid.size())
            return 1e5;
        int ans = 1e5;
        if (i == grid.size() - 1)
            return grid[i][j];
        if (dp[i][j] != 1e6)
            return dp[i][j];
        ans = min(ans, grid[i][j] + dfs(grid, i + 1, j));
        ans = min(ans, grid[i][j] + dfs(grid, i + 1, j + 1));

        return dp[i][j] = ans;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        dp = vector<vector<int>>(triangle.size() + 1,
                                       vector<int>(201, 1e6));
        return dfs(triangle, 0, 0);
    }
};