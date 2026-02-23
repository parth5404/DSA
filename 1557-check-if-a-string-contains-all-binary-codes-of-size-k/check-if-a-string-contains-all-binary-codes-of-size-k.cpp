class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int cnt = pow(2, k);
        unordered_set<string> st;
        for (int i = 0; i + k <= s.length(); i++) {
            string t = s.substr(i, k);
            st.insert(t);
        }
        return cnt == st.size();
    }
};