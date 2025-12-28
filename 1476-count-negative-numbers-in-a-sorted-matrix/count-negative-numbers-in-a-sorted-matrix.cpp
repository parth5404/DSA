class Solution {
public:
    int bs(vector<int>& arr) {
        int e = 0;
        int s = arr.size() - 1;
        int ans = INT_MAX;
        while (e <= s) {
            int mid = s + (e - s) / 2;
            if (arr[mid] < 0) {
                s = mid - 1;
                ans = min(ans, mid);
            } else {
                e = mid + 1;
            }
        }
        return ans;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            if (grid[i].back() < 0) {
                ans+=grid[i].size() - bs(grid[i]);
            }
        }
        return ans;
    }
};