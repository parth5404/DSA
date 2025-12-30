class Solution {
public:
    bool isMagic(vector<vector<int>>& g, int r, int c) {
        unordered_set<int> st;

        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                if (g[i][j] < 1 || g[i][j] > 9) return false;
                st.insert(g[i][j]);
            }
        }
        if (st.size() != 9) return false;

        int sum = g[r][c] + g[r][c+1] + g[r][c+2];

        for (int i = 0; i < 3; i++) {
            if (g[r+i][c] + g[r+i][c+1] + g[r+i][c+2] != sum)
                return false;
            if (g[r][c+i] + g[r+1][c+i] + g[r+2][c+i] != sum)
                return false;
        }

        if (g[r][c] + g[r+1][c+1] + g[r+2][c+2] != sum)
            return false;
        if (g[r][c+2] + g[r+1][c+1] + g[r+2][c] != sum)
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int cnt = 0;

        for (int i = 0; i + 2 < n; i++) {
            for (int j = 0; j + 2 < m; j++) {
                if (grid[i+1][j+1] == 5 && isMagic(grid, i, j))
                    cnt++;
            }
        }
        return cnt;
    }
};
