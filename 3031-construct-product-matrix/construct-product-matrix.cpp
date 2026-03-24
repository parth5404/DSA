class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        vector<vector<long long>> suff(grid.size(),
                                       vector<long long>(grid[0].size(), 1));
        long long fact = 1;
        for (int i = grid.size() - 1; i >= 0; i--) {
            for (int j = grid[i].size() - 1; j >= 0; j--) {
                suff[i][j] = fact;
                fact = (fact * grid[i][j]) % 12345;
            }
        }
        long long pref = 1;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                long long k = grid[i][j];
                grid[i][j] = (int)(pref * suff[i][j]) % 12345;
                pref = (pref * k) % 12345;
            }
        }
        return grid;
    }
};