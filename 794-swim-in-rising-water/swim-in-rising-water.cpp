class Solution {
public:
    vector<vector<bool>> vis;

    bool dfs(vector<vector<int>>& grid, int i, int j, int maxval) {
        if (i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0)
            return false;
        if (grid[i][j] > maxval || vis[i][j])
            return false;

        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return true;
        }
        vis[i][j] = 1;
        return dfs(grid, i + 1, j, maxval) || dfs(grid, i, j + 1, maxval) ||
               dfs(grid, i, j - 1, maxval) || dfs(grid, i - 1, j, maxval);
    }

    int swimInWater(vector<vector<int>>& grid) {
        int s = 0;
        int e = 2502;
        int ans = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            vis = vector<vector<bool>>(grid.size(),
                                       vector<bool>(grid[0].size(), false));
            if (dfs(grid, 0, 0, mid)) {

                e = mid - 1;
                ans = mid;
            } else {
                s = mid + 1;
            }
        }

        return ans;
    }
};