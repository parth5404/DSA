class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int cnt1 = count(s.begin(), s.end(), '1');
        int i = 0;
        vector<int> zero;
        while (i < n) {
            int start = i;
            while (i < n && s[start] == s[i]) {
                i++;
            }
            if (s[start] == '0') {
                zero.push_back(i - start);
            }
        }
        int opt = 0;
        for (int i = 0; i + 1 < zero.size(); i++) {
            opt = max(opt, zero[i] + zero[i + 1]);
        }
        return cnt1 + opt;
    }
};