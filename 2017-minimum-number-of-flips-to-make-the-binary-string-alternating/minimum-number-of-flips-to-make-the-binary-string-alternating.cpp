class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        int ans = INT_MAX;
        int f1 = 0;
        int f2 = 0;
        int i = 0;
        int j = 0;
        while (j < 2 * s.length()) {
            if (j % 2) {
                char des1 = '0';
                char des2 = '1';
                if (s[j % n] != des1)
                    f1++;
                if (s[j % n] != des2)
                    f2++;
            } else {
                char des1 = '1';
                char des2 = '0';
                if (s[j % n] != des1)
                    f1++;
                if (s[j % n] != des2)
                    f2++;
            }
            if (j - i + 1 > n) {
                if (i % 2) {
                    char des1 = '0';
                    char des2 = '1';
                    if (s[i % n] != des1)
                        f1--;
                    if (s[i % n] != des2)
                        f2--;
                } else {
                    char des1 = '1';
                    char des2 = '0';
                    if (s[i % n] != des1)
                        f1--;
                    if (s[i % n] != des2)
                        f2--;
                }
                i++;
            }
            if (j - i + 1 == n) {
                ans = min(ans, min(f1, f2));
            }
            j++;
        }
        return ans;
    }
};