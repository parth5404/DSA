class Solution {
public:
    int dp(string s, int i, int j) {
        if (i == j - 1)
            return 1;
        int oc = 0;
        int idx = -1;
        for (int k = i; k <= j; k++) {
            if (s[k] == '(')
                oc++;
            else
                oc--;
            if (oc == 0) {
                idx = k;
                break;
            }
        }
        int ans = 0;
        if (idx != j) {
            ans += dp(s, i, idx);
            ans += dp(s, idx + 1, j);
        } else {
            ans += 2 * dp(s, i + 1, j - 1);
        }
        return ans;
    }
    int scoreOfParentheses(string s) { return dp(s, 0, s.length() - 1); }
};