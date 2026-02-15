class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;
        while (i >= 0 || j >= 0 || carry > 0) {
            int x = 0;
            if (i >= 0)
                x = a[i] - '0';
            int y = 0;
            if (j >= 0)
                y = b[j] - '0';
            int val = x + y + carry;
            carry = (val >= 2) ? 1 : 0;
            val = val & 1;
            ans += val + '0';
            i--;
            j--;
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};