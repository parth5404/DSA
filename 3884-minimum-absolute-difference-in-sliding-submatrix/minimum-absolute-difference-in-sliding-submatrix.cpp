class Solution {
public:
    vector<vector<int>> ans;
    int p = 0;
    int q = 0;
    void solve(vector<vector<int>>& grid, int k, int i, int j) {
        set<int> st;
        for (int p = i; p <= i + k - 1; p++) {
            for (int q = j; q <= j + k - 1; q++) {
                st.insert(grid[p][q]);
            }
        }
        if (st.size() == 1) {
            ans[i][j] = 0;
            return;
        }
        vector<int> vec(st.begin(), st.end());
        int mini = INT_MAX;
        for (int i = 0; i < vec.size(); i++) {
            for (int j = i + 1; j < vec.size(); j++) {
                mini = min(mini, abs(vec[j] - vec[i]));
            }
        }
        ans[i][j] = mini;
    }
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        this->ans =  vector<vector<int>>(
            grid.size() - k + 1, vector<int>(grid[0].size() - k + 1));
        for (int i = 0; i + k <= grid.size(); i++) {
            for (int j = 0; j + k <= grid[0].size(); j++) {
                solve(grid, k, i, j);
            }
        }
        return ans;
    }
};