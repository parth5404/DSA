class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string ans(n, '#');
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (lcp[j][i] != 0) {
                    ans[i] = ans[j];
                    break;
                }
            }
            if (ans[i] == '#') {
                vector<bool> forb(26, false);
                for (int j = 0; j < i; j++) {
                    if (lcp[j][i] == 0) {
                        forb[ans[j] - 'a'] = 1;
                    }
                }
                for (int idx = 0; idx < 26; idx++) {
                    if (forb[idx] == 0) {
                        ans[i] = idx + 'a';
                        break;
                    }
                }
                if(ans[i]=='#')return "";
            }
        }
         for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (ans[i] != ans[j]) {
                    if (lcp[i][j]) {
                        return "";
                    }
                } else {
                    if (i == n - 1 || j == n - 1) {
                        if (lcp[i][j] != 1) {
                            return "";
                        }
                    } else {
                        if (lcp[i][j] != lcp[i + 1][j + 1] + 1) {
                            return "";
                        }
                    }
                }
            }
        }
        return ans;
        
    }
};