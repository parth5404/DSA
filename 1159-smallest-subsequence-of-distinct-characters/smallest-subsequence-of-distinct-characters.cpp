class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26);
        for (int i = 0; i < s.size(); i++)
            last[s[i] - 'a'] = i;
        stack<char> st;
        vector<bool> inStack(26, false);
        for (int i = 0; i < s.size(); i++) {
            if (inStack[s[i] - 'a'])
                continue;
            while (!st.empty() && st.top() > s[i] && last[st.top() - 'a'] > i) {
                inStack[st.top() - 'a'] = 0;
                st.pop();
            }
            inStack[s[i] - 'a'] = 1;
            st.push(s[i]);
        }
        string str = "";
        while (!st.empty()) {
            str += st.top();
            st.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};