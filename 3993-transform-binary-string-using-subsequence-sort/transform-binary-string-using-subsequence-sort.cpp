class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.size();
        int z = count(s.begin(), s.end(), '0');
        vector<bool> ans;
        for (string t : strs) {
            int zero = 0, ques = 0;
            for (char c : t) {
                if (c == '0')
                    zero++;
                else if (c == '?')
                    ques++;
            }
            int need = z - zero;
            if (need < 0 || need > ques) {
                ans.push_back(false);
                continue;
            }
            for (int i = 0; i < n; i++) {
                if (t[i] == '?') {
                    if (need > 0) {
                        t[i] = '0';
                        need--;
                    } else {
                        t[i] = '1';
                    }
                }
            }
            cout << t << endl;
            bool ok = true;
            int k1 = 0;
            int k2 = 0;
            while (k1 < n && k2 < n) {
                if (s[k1] == '1')
                    k1++;
                if (t[k2] == '1')
                    k2++;
                else if (s[k1] == '0' && t[k2] == '0') {
                    if (k1 < k2) {
                        ok = false;
                    }
                    k1++;
                    k2++;
                }
            }

            ans.push_back(ok);
        }

        return ans;
    }
};