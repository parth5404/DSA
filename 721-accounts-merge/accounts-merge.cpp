class Solution {
public:
    vector<int> parent, size;
    void sett(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int findUpar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findUpar(parent[node]);
    }
    void unionBysz(int u, int v) {
        int parU = findUpar(u);
        int parV = findUpar(v);
        if (parU == parV)
            return;
        if (size[parU] > size[parV]) {
            parent[parV] = parU;
            size[parU] += size[parV];
        } else {
            parent[parU] = parV;
            size[parV] += size[parU];
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        int n = acc.size();
        sett(n);
        unordered_map<string, int> mp;
        for (int j = 0; j < n; j++) {
            auto it = acc[j];
            for (int i = 1; i < it.size(); i++) {
                if (mp.find(it[i]) == mp.end()) {
                    mp[it[i]] = j;
                } else {
                    unionBysz(j, mp[it[i]]);
                }
            }
        }
        vector<string> merge[n];
        for (auto it : mp) {
            string mail = it.first;
            int par = findUpar(it.second);
            merge[par].push_back(mail);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (merge[i].size() == 0)
                continue;
            string tag = acc[i][0];
            sort(merge[i].begin(), merge[i].end());
            vector<string> temp;
            temp.push_back(tag);
            for (auto it : merge[i])
                temp.push_back(it);
            ans.push_back(temp);
        }
        return ans;
    }
};