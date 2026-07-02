class Solution {
public:
    vector<array<int, 2>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> best(n, vector<int>(m, -1));
        health -= grid[0][0];
        if (health < 1)
            return false;
        queue<array<int, 3>> q;
        q.push({0, 0, health});
        best[0][0] = health;
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            if (top[0] == n - 1 && top[1] == m - 1) {
                return true;
            }
            for (auto it : dir) {
                int x = top[0] + it[0];
                int y = top[1] + it[1];
                if (x >= 0 && x < n && y >= 0 && y < m) {
                    int newH = top[2] - grid[x][y];
                    if (newH >= 1 && newH > best[x][y]) {
                        best[x][y] = newH;
                        q.push({x, y, newH});
                    }
                }
            }
        }
        return false;
    }
};