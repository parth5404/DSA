class Solution {
public:
    unordered_set<int> st;
    unordered_map<int, vector<int>> mp;
    vector<int> indegree;
    void dfs(int k) {
        if (st.find(k) != st.end()) {
            return;
        }
        st.insert(k);
        for (int i=0;i<mp[k].size();i++) {
            indegree[mp[k][i]]--;
            dfs(mp[k][i]);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& inv) {
        indegree = vector<int>(n, 0);
        for (int i = 0; i < inv.size(); i++) {
            mp[inv[i][0]].push_back(inv[i][1]);
            indegree[inv[i][1]]++;
        }
        dfs(k);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (st.find(i) != st.end()) {
                if (indegree[i] > 0)
                    ans.push_back(i);
            } else {
                vector<int>all;
                for(int k=0;k<mp[i].size();k++){
                    if(st.find(mp[i][k])!=st.end()){
                        for(int j=0;j<n;j++){
                            all.push_back(j);
                        }
                        return all;
                    }   
                }
                ans.push_back(i);
            }
        }
        return ans;
    }
};