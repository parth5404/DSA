class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        int n = word.length();
        if (n <= 8) {
            return n;
        }
        int k = n / 8;
        int p = n % 8;
        ans += 4 * (k * (k + 1));
        ans += (k + 1) * p;
        return ans;
    }
};