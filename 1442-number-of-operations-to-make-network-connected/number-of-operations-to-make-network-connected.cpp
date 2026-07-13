class Solution {
public:
    unordered_map<int, vector<int>> mp;
    vector<int> vis;
    vector<int> parent;
    vector<int> size;
    void sett(int n) {
        parent = vector<int>(n, 0);
        size = vector<int>(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int findPar(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }
    void unionBysz(int u, int v) {
        int parU = findPar(u);
        int parV = findPar(v);
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
    int makeConnected(int n, vector<vector<int>>& conn) {
        if (n - 1 > conn.size())
            return -1;
        sett(n);
        for (auto it : conn) {
            unionBysz(it[0], it[1]);
        }
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(findPar(i));
        }
        return st.size() - 1;
    }
};