class Solution {
public:
    vector<int> dp;
    vector<int> pre;
    bool solve(string& s, int idx, int& mij, int& maj) {
        if (idx == s.length() - 1)
            return true;
        if (dp[idx] != -1)
            return (dp[idx] == 0) ? 0 : 1;
        bool ans = false;
        for (int i = idx + mij; i <= min(idx + maj, (int)s.length() - 1); i++) {
            if (s[i] == '0') {
                ans = ans | solve(s, i, mij, maj);
            }
        }

        return dp[idx] = (ans == 0) ? 0 : 1;
    }
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        dp = vector<int>(s.length(), 0);
        pre = vector<int>(s.length(), 0);
        dp[0] = 1;
        pre[0] = 1;
        for (int i = 1; i < minJump; i++) {
            pre[i] = pre[i - 1];
        }
        for (int i = minJump; i < n; i++) {
            if (s[i] == '0') {
                int mini = i - minJump;
                int maxi = ((i - maxJump) < 0) ? 0 : i - maxJump;

                dp[i] = pre[mini] - ((maxi - 1) < 0 ? 0 : pre[maxi - 1]);
                if (dp[i] > 0)
                    dp[i] = 1;
            }
            pre[i] = pre[i - 1] + dp[i];
        }
        return dp[n - 1];
    }
};