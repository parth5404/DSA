class DSU {
public:
    int n;
    vector<int> parent;
    vector<int> rank;

    DSU(int n) {
        this->n = n;
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int val) {
        if (parent[val] == val) {
            return val;
        }
        return parent[val] = find(parent[val]);
    }

    void unite(int val1, int val2) {
        int r1 = find(val1);
        int r2 = find(val2);

        if (r1 == r2)
            return;

        if (rank[r1] > rank[r2]) {
            parent[r2] = r1;
        } else if (rank[r1] < rank[r2]) {
            parent[r1] = r2;
        } else {
            parent[r2] = r1;
            rank[r1]++;
        }
    }
};
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target,
                               vector<vector<int>>& as) {
        DSU dsu(source.size());
     //   unordered_map<int, vector<int>> adj;
        for (int i = 0; i < as.size(); i++) {
            // adj[as[i][0]].push_back(as[i][1]);
            // adj[as[i][1]].push_back(as[i][0]);
            dsu.unite(as[i][0], as[i][1]);
        }
        unordered_map<int, unordered_map<int, int>> mp;
        int cnt = 0;
        for (int i = 0; i < source.size(); i++) {
            int parent = dsu.find(i);
            mp[parent][source[i]]++;
        }
        for (int i = 0; i < target.size(); i++) {
            int parent = dsu.find(i);
            if (mp[parent][target[i]] > 0) {
                mp[parent][target[i]]--;
            } else {
                cnt++;
            }
        }
        return cnt;
    }
};
