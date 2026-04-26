class Solution {
public:
    vector<array<int, 2>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<bool>> vis;
    bool dfs(vector<vector<char>>& grid, int i, int j, int pi, int pj) {
        vis[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int x = i + dir[k][0];
            int y = j + dir[k][1];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() &&
                grid[i][j] == grid[x][y]) {
                if (!vis[x][y]) {
                    if (dfs(grid, x, y, i, j))
                        return true;
                } else if (x != pi || y != pj) {
                    return true;
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        vis = vector<vector<bool>>((int)grid.size(),
                                   vector<bool>((int)grid[0].size(), 0));
        bool check = false;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (!vis[i][j]) {
                    check = dfs(grid, i, j, -1, -1);
                    if (check) {
                        return true;
                    }
                }
            }
        }
        return check;
    }
};