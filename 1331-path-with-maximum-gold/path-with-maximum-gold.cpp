class Solution {
public:
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    vector<vector<int>> vis;

    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return 0;
        if (vis[i][j] == 1 || grid[i][j] == 0)
            return 0;
        vis[i][j] = 1;
        int best = 0;
        for (int k = 0; k < 4; k++) {
            best = max(best, dfs(grid, i + dir[k].first, j + dir[k].second));
        }
        vis[i][j] = 0;
        return grid[i][j] + best;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        vis.assign(grid.size(), vector<int>(grid[0].size(), 0));

        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] != 0) {
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }
        return ans;
    }
};
