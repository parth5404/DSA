class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        int cnt=0;
        int ans=0;
        unordered_set<char>st;
        while(j<s.length()){
            if(st.find(s[j])==st.end()){
                st.insert(s[j]);
                j++;
            }
            else{
                while(st.find(s[j])!=st.end()){
                    st.erase(s[i]);
                    i++;
                }
            }
            ans=max(ans,j-i);
        }
        return ans;
    }
};