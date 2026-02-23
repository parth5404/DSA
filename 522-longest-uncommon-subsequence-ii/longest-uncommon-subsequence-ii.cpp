class Solution {
public:
    static bool comp(string s, string t) { return s.length() < t.length(); }
    bool check(string s, string t) {
        int i = 0;
        for (char& ch : t) {
            if (i < s.length() && s[i] == ch) {
                i++;
            }
        }
        return i == s.length();
    }
    int findLUSlength(vector<string>& strs) {
        int ans = -1;
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            bool flag = 0;
            for (int j = 0; j < strs.size(); j++) {
                string t = strs[j];
                if (j != i && check(s, t)) {
                    flag = 1;
                    break;
                }
            }
            if (!flag)
                ans = max(ans, (int)s.length());
        }

        return ans;
    }
};