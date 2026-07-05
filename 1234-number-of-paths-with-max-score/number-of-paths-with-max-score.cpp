class Solution {
public:
    int max_sum = INT_MIN;
    int max_cnt = 0;
    vector<array<int, 2>> dir = {{-1, 0}, {0, -1}, {-1, -1}};
    int MOD = 1e9 + 7;
    vector<vector<array<int, 2>>> dp;
    array<int, 2> dfs(vector<string>& board, int i, int j) {
        if (i == 0 && j == 0) {
            return {0, 1};
        }
        if (dp[i][j][0] != -1) {
            return dp[i][j];
        }
        array<int, 2> ans = {0, 0};
        for (auto it : dir) {
            int x = i + it[0];
            int y = j + it[1];
            if (x >= 0 && y >= 0 && board[x][y] != 'X') {
                if (board[x][y] >= '1' && board[x][y] <= '9') {
                    int val = board[x][y] - '0';
                    if (ans[0] < val + dfs(board, x, y)[0]) {
                        ans[0] = max(ans[0], val + dfs(board, x, y)[0]);
                        ans[1] = (dfs(board, x, y)[1]) % MOD;
                    } else if (ans[0] == val + dfs(board, x, y)[0]) {
                        ans[0] = max(ans[0], val + dfs(board, x, y)[0]);
                        ans[1] = (ans[1] + dfs(board, x, y)[1]) % MOD;
                    }
                } else if (x == 0 && y == 0) {
                    int val = 0;
                    if (ans[0] < val + dfs(board, x, y)[0]) {
                        ans[0] = max(ans[0], val + dfs(board, x, y)[0]);
                        ans[1] = (dfs(board, x, y)[1]) % MOD;
                    } else if (ans[0] == val + dfs(board, x, y)[0]) {
                        ans[0] = max(ans[0], val + dfs(board, x, y)[0]);
                        ans[1] = (ans[1] + dfs(board, x, y)[1]) % MOD;
                    }
                }
            }
        }
        return dp[i][j] = ans;
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        dp = vector<vector<array<int, 2>>>(
            n + 1, vector<array<int, 2>>(n + 1, {-1, 0}));
        vector<vector<int>> scores(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (board[i][j] == 'S') {
                    scores[i][j] = 0;
                    ways[i][j] = 1;
                    continue;
                }
                if (board[i][j] == 'X')
                    continue;
                array<int, 2> arr = {-1, 0};
                if (i + 1 < n && j + 1 < n && board[i + 1][j + 1] != 'X') {
                    if (scores[i + 1][j + 1] > arr[0]) {
                        arr[0] = scores[i + 1][j + 1];
                        arr[1] = ways[i + 1][j + 1];
                    } else if (scores[i + 1][j + 1] == arr[0]) {
                        arr[1] = (arr[1] + ways[i + 1][j + 1]) % MOD;
                    }
                }
                if (i + 1 < n && board[i + 1][j] != 'X') {
                    if (scores[i + 1][j] > arr[0]) {
                        arr[0] = scores[i + 1][j];
                        arr[1] = ways[i + 1][j];
                    } else if (scores[i + 1][j] == arr[0]) {
                        arr[1] = (arr[1] + ways[i + 1][j]) % MOD;
                    }
                }
                if (j + 1 < n && board[i][j + 1] != 'X') {
                    if (scores[i][j + 1] > arr[0]) {
                        arr[0] = scores[i][j + 1];
                        arr[1] = ways[i][j + 1];
                    } else if (scores[i][j + 1] == arr[0]) {
                        arr[1] = (arr[1] + ways[i][j + 1]) % MOD;
                    }
                }
                if (arr[0] == -1)
                    continue;
                int val = 0;
                if (board[i][j] >= '0' && board[i][j] <= '9')
                    val = board[i][j] - '0';
                scores[i][j] = val + arr[0];
                ways[i][j] = arr[1];
            }
        }
        if (ways[0][0] == 0)
            return {0, 0};
        return {dfs(board, n - 1, n - 1)[0], dfs(board, n - 1, n - 1)[1]};
    }
};