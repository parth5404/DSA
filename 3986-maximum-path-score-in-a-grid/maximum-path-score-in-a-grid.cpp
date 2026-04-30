class Solution {
public:
    vector<vector<vector<int>>> dp;
    long long dfs(vector<vector<int>>& grid, int k, int i, int j) {

        if (i >= grid.size() || j >= grid[0].size())
            return -1;

        int remk = (grid[i][j] > 0) ? 1 : 0;
        k -= remk;

        if (k < 0)
            return -1;
        if (dp[i][j][k] != -2)
            return dp[i][j][k];
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return grid[i][j];
        }

        long long right = dfs(grid, k, i, j + 1);
        long long down = dfs(grid, k, i + 1, j);

        if (right == -1 && down == -1)
            return dp[i][j][k] = -1;

        return dp[i][j][k] = grid[i][j] + max(right, down);
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        dp.assign(m, vector<vector<int>>(n, vector<int>(k + 1, -2)));
        return dfs(grid, k, 0, 0);
    }
};