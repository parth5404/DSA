class Solution {
public:
    int setbits(int val) {
        int ans = 0;
        while (val != 0) {
            if (val & 1)
                ans++;
            val = val >> 1;
        }
        return ans;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 60; j++) {
                if (setbits(i) + setbits(j) == turnedOn) {
                    ans.push_back(to_string(i) + ":" + (j < 10 ? "0" : "") +
                                  to_string(j));
                }
            }
        }
        return ans;
    }
};