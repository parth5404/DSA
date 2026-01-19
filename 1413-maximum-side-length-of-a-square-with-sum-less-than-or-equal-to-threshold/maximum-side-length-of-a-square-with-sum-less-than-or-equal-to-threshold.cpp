class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        
        // prefix sum matrix
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] = mat[i-1][j-1]
                             + prefix[i-1][j]
                             + prefix[i][j-1]
                             - prefix[i-1][j-1];
            }
        }

        int ans = 0;

        // try all possible top-left corners
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // try increasing square size
                for (int len = ans + 1;
                     i + len - 1 <= m && j + len - 1 <= n;
                     len++) {

                    int sum = prefix[i + len - 1][j + len - 1]
                            - prefix[i - 1][j + len - 1]
                            - prefix[i + len - 1][j - 1]
                            + prefix[i - 1][j - 1];

                    if (sum <= threshold)
                        ans = len;
                    else
                        break;
                }
            }
        }
        return ans;
    }
};
