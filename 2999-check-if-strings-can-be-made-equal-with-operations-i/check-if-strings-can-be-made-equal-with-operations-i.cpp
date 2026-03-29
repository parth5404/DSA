class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int j = 0;
        for (int i = 0; i + 2 < 4; i++) {
            if (s1[i] == s2[j + 2] && s1[i + 2] == s2[j])
                swap(s1[i], s1[i + 2]);
            j++;
        }
        return s1 == s2;
    }
};