class Solution {
public:
    string solve(string s) {
        vector<string> res;
        int sum = 0;
        int start = 0;
        for (int i = 0; i < s.length(); i++) {
            sum += (s[i] == '0') ? -1 : 1;
            if (sum == 0) {
                string inner = s.substr(start + 1, i - start - 1);
                res.push_back("1" + solve(inner) + "0");
                start=i+1;
            }
        }
        sort(res.begin(), res.end());
        string ans = "";
        for (int i = res.size() - 1; i >= 0; i--) {
            ans += res[i];
        }
        return ans;
    }
    string makeLargestSpecial(string s) {
        return solve(s);
    }
};