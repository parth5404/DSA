class Solution {
public:
    int check(string& s, int i, int j) {
        int ans = 0;
        while (i >= 0 && j < s.length() && s[i] == s[j]) {
            ans = max(ans, j - i + 2);
            i--;
            j++;
        }
        int sl = i - 1;
        int sr = j;
        while (sl >= 0 && sr < s.length() && s[sl] == s[sr]) {
            ans = max(ans, sr - sl + 1);
            sl--;
            sr++;
        }
        sl = i;
        sr = j + 1;
        while (sl >= 0 && sr < s.length() && s[sl] == s[sr]) {
            ans = max(ans, sr - sl + 1);
            sl--;
            sr++;
        }
        return ans;
    }
    int almostPalindromic(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            ans = max(ans, max(check(s, i, i + 1), check(s, i, i)));
        }
        return min(ans,(int)s.length());
    }
};
