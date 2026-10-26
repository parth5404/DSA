class Solution {
public:
    vector<array<int, 2>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> vis;
    int n, m;
    long long dfs(int k, vector<vector<int>>& grid, int i, int j) {
        vis[i][j] = 1;
        long long sum = 0;
        for (auto [x1, y1] : dirs) {
            int x = i + x1;
            int y = j + y1;
            if (x < 0 || x >= n || y < 0 || y >= m)
                continue;
            if (grid[x][y] == 0 || vis[x][y] == 1)
                continue;
            sum += dfs(k, grid, x, y);
        }
        return sum + grid[i][j];
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        vis = vector<vector<int>>(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0 && vis[i][j] == 0) {
                    long long val = dfs(k, grid, i, j);
                    if (val % k == 0)
                        ans++;
                }
            }
        }
        return ans;
    }
};