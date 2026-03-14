class Solution {
public:
    char arr[3] = {'a','b','c'};
    string ans = "";
    void bcK(int n, int &k, string &str) {
        if (str.length() == n) {
            k--;
            if (k == 0) ans = str;
            return;
        }

        for (int i = 0; i < 3; i++) {
            if (!ans.empty()) return; 

            if (str.empty() || str.back() != arr[i]) {
                str.push_back(arr[i]);
                bcK(n, k, str);
                str.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        string str = "";
        bcK(n, k, str);
        return ans;
    }
};