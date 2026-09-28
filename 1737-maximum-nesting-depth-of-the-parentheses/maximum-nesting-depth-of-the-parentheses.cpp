class Solution {
public:
    int maxDepth(string s) {
        int run = 0;
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                run++;
            if (s[i] == ')')
                run--;

            ans = max(ans, run);
        }
        return ans;
    }
};