class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        for (char ch : num) {
            while (!ans.empty() && k > 0 && ch < ans.back()) {
                k--;
                ans.pop_back();
            }
            ans += ch;
        }
        while (k > 0 && !ans.empty()) {
            ans.pop_back();
            k--;
        }
        int st = 0;
        for (char c : ans) {
            if (c != '0')
                break;
            st++;
        }
        ans = ans.substr(st);

        return ans.empty() ? "0" : ans;
    }
};