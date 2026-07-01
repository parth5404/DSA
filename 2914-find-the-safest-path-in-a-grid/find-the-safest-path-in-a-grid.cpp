class Solution {
public:
    vector<array<int, 2>> vec = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool bfs(vector<vector<int>>& grid, int val) {
        int n = grid.size();

        if (grid[0][0] < val)
            return false;

        queue<array<int, 2>> q;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        q.push({0, 0});
        vis[0][0] = 1;

        while (!q.empty()) {
            auto top = q.front();
            q.pop();

            if (top[0] == n - 1 && top[1] == n - 1)
                return true;

            for (auto it : vec) {
                int x = top[0] + it[0];
                int y = top[1] + it[1];

                if (x >= 0 && x < n && y >= 0 && y < n &&
                    !vis[x][y] && grid[x][y] >= val) {

                    vis[x][y] = 1;
                    q.push({x, y});
                }
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        queue<array<int, 3>> q;
        int n = grid.size();

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    q.push({i, j, 0});
                } else {
                    grid[i][j] = -1;
                }
            }
        }

        int maxi = 0;

        while (!q.empty()) {
            auto top = q.front();
            q.pop();

            for (auto it : vec) {
                int x = top[0] + it[0];
                int y = top[1] + it[1];

                if (x >= 0 && x < n && y >= 0 && y < n &&
                    grid[x][y] == -1) {

                    grid[x][y] = top[2] + 1;
                    maxi = max(maxi, top[2] + 1);
                    q.push({x, y, top[2] + 1});
                }
            }
        }

        int low = 0, high = maxi, ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (bfs(grid, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};