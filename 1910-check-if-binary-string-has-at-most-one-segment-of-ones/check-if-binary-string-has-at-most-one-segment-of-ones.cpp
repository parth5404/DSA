class Solution {
public:
    bool checkOnesSegment(string s) {
        int idx = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                if (idx != -1) {
                    if (i - idx > 1)
                        return false;
                }
                idx = i;
            }
        }
        return true;
    }
};