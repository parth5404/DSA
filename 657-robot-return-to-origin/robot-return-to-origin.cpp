class Solution {
public:
    bool judgeCircle(string moves) {
        int l = 0, r = 0, u = 0, d = 0;
        for (char &ch : moves) {
            if (ch == 'U')
                u++;
            else if (ch == 'L')
                l++;
            else if (ch == 'D')
                d++;
            else if (ch == 'R')
                r++;
        }
        return l == r && u == d;
    }
};