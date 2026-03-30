class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<int, unordered_map<char, int>> mp;
        for (int i = 0; i < s1.length(); i++) {
            mp[i % 2][s1[i]]++;
        }
        for (int i = 0; i < s2.length(); i++) {
            auto& it = mp[i % 2];
            if (it.count(s2[i])) {
                it[s2[i]]--;
                if (it[s2[i]] == 0) {
                    it.erase(s2[i]);
                }
            } else {
                return false;
            }
        }
        return true;
    }
};