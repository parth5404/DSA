class Solution {
public:
    int max_sum = INT_MIN;
    int max_cnt = 0;
    vector<array<int, 2>> dir = {{-1, 0}, {0, -1}, {-1, -1}};
    int MOD = 1e9 + 7;
    // vector<vector<int>> dp(102, vector<int>(102, 0));
    // int dfs(vector<string>& board, int i, int j, int sum) {
    //     if (i == 0 && j == 0) {
    //         if (sum > max_sum) {
    //             max_sum = sum;
    //             max_cnt = 1;
    //         } else if (sum == max_sum) {
    //             max_cnt++;
    //         }
    //         //  cout << "Base Case" << endl;
    //         return 0;
    //     }
    //     if (dp[i][j] != -1) {
    //         return dp[i][j];
    //     }
    //     // for (auto it : dir) {
    //     //     int x = i + it[0];
    //     //     int y = j + it[1];
    //     //     if (x >= 0 && y >= 0 && board[x][y] != 'X') {
    //     //         if (board[x][y] >= '1' && board[x][y] <= '9') {
    //     //             int val = (sum + board[x][y] - '0') % MOD;
    //     //             // cout << x << " " << y << " " << board[x][y] << " "
    //     <<
    //     //             val
    //     //             //      << endl;
    //     //             dp[i] dfs(board, x, y, val);
    //     //         } else if (x == 0 && y == 0) {
    //     //             dfs(board, x, y, sum % MOD);
    //     //         }
    //     //     }
    //     // }
    //     dp[i][j] = val + max()
    // }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
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
                // diagonal
                if (i + 1 < n && j + 1 < n && board[i + 1][j + 1] != 'X') {
                    if (scores[i + 1][j + 1] > arr[0]) {
                        arr[0] = scores[i + 1][j + 1];
                        arr[1] = ways[i + 1][j + 1];
                    } else if (scores[i + 1][j + 1] == arr[0]) {
                        arr[1] = (arr[1] + ways[i + 1][j + 1]) % MOD;
                    }
                }
                // down
                if (i + 1 < n && board[i + 1][j] != 'X') {
                    if (scores[i + 1][j] > arr[0]) {
                        arr[0] = scores[i + 1][j];
                        arr[1] = ways[i + 1][j];
                    } else if (scores[i + 1][j] == arr[0]) {
                        arr[1] = (arr[1] + ways[i + 1][j]) % MOD;
                    }
                }
                // right
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
        return {scores[0][0], ways[0][0]};
    }
};