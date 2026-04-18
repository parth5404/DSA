class Solution {
public:
 int palat(int nums) {
        string s = to_string(nums);
        reverse(s.begin(), s.end());
        int i = 0;
        while (i < s.length() && s[i] == '0')
            i++;
        string res = s.substr(i);
        return res.empty() ? 0 : stoi(res);
    }
    int mirrorDistance(int n) {
        return abs(n-palat(n));
    }
};