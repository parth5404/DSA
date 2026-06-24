class Solution {
public:
    int MOD = 1e9 + 7;
    using Matrix = vector<vector<long long>>;
    Matrix mul(const Matrix& a, const Matrix& b) {
        int n = a.size();
        int m = b[0].size();
        Matrix res(n, vector<long long>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < a[0].size(); k++) {
                long long r = a[i][k];
                if (r == 0) {
                    continue;
                }
                for (int j = 0; j < m; j++) {
                    res[i][j] = (res[i][j] + r * b[k][j]) % MOD;
                }
            }
        }
        return res;
    }
    Matrix powMul(Matrix& m1, Matrix& m2, int times) {
    Matrix res = m2;

    while (times > 0) {
        if (times & 1) {
            res = mul(res, m1);
        }

        m1 = mul(m1, m1);
        times >>= 1;
    }

    return res;
}

int zigZagArrays(int n, int l, int r) {
    int m = r - l + 1;
    Matrix idt(2 * m, vector<long long>(2 * m, 0));
    for (int i = m + 1; i < 2 * m; i++) {
        for (int j = 0; j < i - m; j++) {
            idt[i][j] = 1;
            idt[2 * m - 1 - i][j] = 1;
        }
    }
    Matrix dp(1, vector<long long>(2 * m, 1));
    dp = powMul(idt, dp, n - 1);

    int ans = 0;
    for (int i = 0; i < 2 * m; i++) {
        ans = (ans + dp[0][i]) % MOD;
    }

    return ans;
}
};