class Solution {
public:
    string reverseParentheses(string s) {
        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z' || s[i] == '(')
                ans += s[i];
            else {
                string temp = "";
                while (!ans.empty() && ans.back() != '(') {
                    temp += ans.back();
                    ans.pop_back();
                }
                ans.pop_back();
                ans += temp;
            }
        }
        return ans;
    }
};