class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for (int i = 0; i < words.size(); i++) {
            int val = 0;
            for (char& ch : words[i]) {
                val += weights[ch-'a'];
            }
            val = val % 26;
            ans += (25-val) + 'a';
        }
        return ans;
    }
};