class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int cnt = pow(2,k);
        unordered_set<string> st;
        for (int i = k; i <= s.length(); i++) {
            string t = s.substr(i - k, k);
            st.insert(t);
        }
        return cnt == st.size();
    }
};