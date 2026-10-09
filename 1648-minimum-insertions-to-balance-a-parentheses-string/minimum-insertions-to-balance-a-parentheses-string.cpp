class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int ans = 0;
        int i = 0;
        while (i < s.length()) {
            if (s[i] == '(') {
                st.push(s[i]);
                i++;
            } else if (s[i] == ')') {
                if (i + 1 < s.length() && s[i + 1] == ')') {
                    if (!st.empty() && st.top() == '(') {
                        st.pop();
                    } else {
                        ans += 1;
                    }
                    i += 2;
                } else {
                    if (!st.empty() && st.top() == '(') {
                        st.pop();
                        ans += 1;
                    } else {
                        ans += 2;
                    }
                    i++;
                }
            }
        }
        ans += st.size() * 2;
        return ans;
    }
};