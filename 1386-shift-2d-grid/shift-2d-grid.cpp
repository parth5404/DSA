class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int k1 = k, k2 = k;
        int nums = grid.size() * grid[0].size();
        if (k > nums) {
            k = k % nums;
        }
        vector<vector<int>> ans(grid.size(), vector<int>(grid[0].size()));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                int y = i * grid[0].size();
                int x = (y + j + k) % nums;
                ans[x / grid[0].size()][x % grid[0].size()] = grid[i][j];
            }
        }
        return ans;
    }
};