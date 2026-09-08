class Solution {
public:
    int countCommas(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            string s = to_string(i);
            if (s.length() < 4)
                ans += 0;
            else
                ans += (s.length() - 1) / 3;
        }
        return ans;
    }
};