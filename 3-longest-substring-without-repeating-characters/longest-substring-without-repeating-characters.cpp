class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        int ans=0;
        unordered_set<char>st;
        while(j<s.length()){
            while(st.count(s[j])){
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};