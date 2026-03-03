class Solution {
public:
    string invert(string s) {
        for (int i = 0; i < s.length(); i++) {
            s[i] = (s[i] - '0' == 0) ? '1' : '0';
        }
        int i = 0;
        int j = s.length() - 1;
        while (i <= j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }

        return s;
    }
    char findKthBit(int n, int k) {
        string prev = "0";
        for (int i = 1; i < n; i++) {
            string temp = invert(prev);
            prev = prev + "1" + temp;
        }
        return prev[k-1];
    }
};