class Solution {
public:
    vector<int> dp;

    int solve(vector<int>& arr, int d, int idx) {
        if (dp[idx] != -1) return dp[idx];

        int ans = 1;

        // right
        for (int i = idx + 1; i < arr.size() && i <= idx + d; i++) {

            if (arr[i] >= arr[idx]) break;

            ans = max(ans, 1 + solve(arr, d, i));
        }

        // left
        for (int i = idx - 1; i >= 0 && i >= idx - d; i--) {

            if (arr[i] >= arr[idx]) break;

            ans = max(ans, 1 + solve(arr, d, i));
        }

        return dp[idx] = ans;
    }

    int maxJumps(vector<int>& arr, int d) {

        int n = arr.size();

        dp.resize(n, -1);

        int ans = 1;

        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(arr, d, i));
        }

        return ans;
    }
};