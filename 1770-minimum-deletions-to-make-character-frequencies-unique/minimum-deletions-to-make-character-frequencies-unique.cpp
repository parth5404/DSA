class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        unordered_set<int> st;
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        sort(freq.begin(), freq.end());
        int del = 0;
        for (auto it : freq) {
            if (it == 0)
                continue;
            if (st.empty())
                st.insert(it);
            else {
                int val = it;
                while (st.find(val) != st.end() && val > 0) {
                    val--;
                    del++;
                }
                if (val > 0)
                    st.insert(val);
            }
        }
        return del;
    }
};