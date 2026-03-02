class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trailing(n);
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = n - 1; j >= 0 && grid[i][j] == 0; j--) {
                count++;
            }
            trailing[i] = count;
        }
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            int required = n - i - 1;
            int j = i;
            while (j < n && trailing[j] < required) {
                j++;
            }
            if (j == n)
                return -1;
            while (j > i) {
                swap(trailing[j], trailing[j - 1]);
                swaps++;
                j--;
            }
        }

        return swaps;
    }
};