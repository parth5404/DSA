class Solution {
public:
    string reorganizeString(string s) {
        vector<pair<int, char>> freq(26);
        int max_freq = 0;
        for (char ch : s) {
            freq[ch - 'a'].first++;
            freq[ch - 'a'].second = ch;
            max_freq = max(max_freq, freq[ch - 'a'].first);
        }
        if (max_freq > (s.size() + 1) / 2)
            return "";
        sort(freq.begin(), freq.end());
        string ans = s;
        int k = 0;
        for (int i = freq.size() - 1; i >= 0; i--) {
            if (freq[i].first == 0)
                break;
            while (freq[i].first != 0) {
                ans[k] = freq[i].second;
                k = k + 2;
                if (k >= ans.size()) {
                    k = 1;
                }
                freq[i].first--;
            }
        }
        return ans;
    }
};