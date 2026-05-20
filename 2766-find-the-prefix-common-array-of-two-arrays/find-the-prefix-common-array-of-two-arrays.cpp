class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans(A.size(), 0);
        unordered_map<int, int> mp;
        mp[A[0]]++;
        mp[B[0]]++;
        if (A[0] == B[0])
            ans[0] = 1;
        for (int i = 1; i < A.size(); i++) {
            mp[A[i]]++;
            mp[B[i]]++;
            if (A[i] == B[i])
                ans[i] = ans[i - 1] + 1;
            else {
                if (mp[A[i]] == 2 && mp[B[i]] == 2)
                    ans[i] = ans[i - 1] + 2;
                else if (mp[A[i]] != mp[B[i]])
                    ans[i] = ans[i - 1] + 1;
                else {
                    ans[i] = ans[i - 1];
                }
            }
        }
        return ans;
    }
};