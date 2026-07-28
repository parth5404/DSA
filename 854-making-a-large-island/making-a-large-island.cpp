class Solution {
public:
    vector<array<int, 2>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int val = 0;
    void dfs(vector<vector<int>>& grid, int i, int j, int uid) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return;
        if (grid[i][j] != 1) {
            return;
        }
        grid[i][j] = uid;
        val++;
        for (auto it : dir) {
            dfs(grid, i + it[0], j + it[1], uid);
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int uid = 2;
        unordered_map<int, int> mp;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, uid);
                    mp[uid] = val;
                    val = 0;
                    uid++;
                }
            }
        }
        int ans = 0;
        bool hasZero = false;
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 0) {
                    hasZero = true;

                    unordered_set<int> st;
                    int curr = 1;

                    for (auto [dx, dy] : dir) {
                        int ni = i + dx;
                        int nj = j + dy;

                        if (ni >= 0 && ni < n && nj >= 0 && nj < n &&
                            grid[ni][nj] > 1) {
                            st.insert(grid[ni][nj]);
                        }
                    }

                    for (int id : st)
                        curr += mp[id];

                    ans = max(ans, curr);
                }
            }
        }

        if (!hasZero)
            return n * n;

        return ans;
    }
};