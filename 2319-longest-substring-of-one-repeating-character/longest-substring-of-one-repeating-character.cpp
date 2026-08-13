class Solution {
public:
    vector<int> longestRepeating(string s, string qc, vector<int>& qi) {
        int n = s.size();
        set<pair<int, int>> segs;
        multiset<int> lens;
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && s[j] == s[i]) {
                j++;
            }
            segs.insert({i, j - 1});
            lens.insert(j - i);
            i = j;
        }
        int k = qi.size();
        vector<int> ans(k, 0);

        for (int i = 0; i < qi.size(); i++) {
            if (s[qi[i]] == qc[i]) {
                ans[i] = *lens.rbegin();
            } else {
                auto it = segs.upper_bound({qi[i], INT_MAX});
                --it;
                int L = it->first, R = it->second;
                segs.erase(it);
                lens.erase(lens.find(R - L + 1));
                int pos = qi[i];
                if (L <= pos - 1) {
                    segs.insert({L, pos - 1});
                    lens.insert(pos - L);
                }
                if (pos + 1 <= R) {
                    segs.insert({pos + 1, R});
                    lens.insert(R - pos);
                }
                int newL = pos, newR = pos;
                auto leftIt = segs.lower_bound({pos, 0});
                if (leftIt != segs.begin()) {
                    leftIt--;
                    int lc_l = leftIt->first;
                    int lc_r = leftIt->second;
                    if (lc_r == pos - 1 && s[lc_r] == qc[i]) {
                        newL = lc_l;
                        segs.erase({lc_l, lc_r});
                        lens.erase(lens.find(lc_r - lc_l + 1));
                    }
                }
                auto rightIt = segs.lower_bound({pos+1, 0});
                if (rightIt != segs.end()) {
                    int lc_l = rightIt->first;
                    int lc_r = rightIt->second;
                    if (lc_l == pos + 1 && s[lc_l] == qc[i]) {
                        newR = lc_r;
                        segs.erase({lc_l, lc_r});
                        lens.erase(lens.find(lc_r - lc_l + 1));
                    }
                }
                segs.insert({newL,newR});
                lens.insert({newR-newL+1});
                s[pos] = qc[i];
                ans[i] = *lens.rbegin();
            }
        }
        return ans;
    }
};