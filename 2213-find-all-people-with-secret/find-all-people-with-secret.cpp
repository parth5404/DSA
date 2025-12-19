
class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int getParent(int val) {
        if (parent[val] != val) {
            parent[val] = getParent(parent[val]);
        }
        return parent[val];
    }
    static bool comp(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    };
    void unionAll(int a, int b) {
        int pa = getParent(a);
        int pb = getParent(b);
        if (pa == pb)
            return;
        if (rank[pa] < rank[pb])
            parent[pa] = pb;
        else if (rank[pa] > rank[pb])
            parent[pb] = pa;
        else {
            rank[pa]++;
            parent[pb] = pa;
        }
    }
    void reset(int val) {
        parent[val] = val;
        rank[val] = 0;
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int fp) {
        sort(meetings.begin(), meetings.end(), comp);
        this->rank = vector<int>(n, 0);
        this->parent = vector<int>(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
        unionAll(0, fp);
        int i=0;
        while (i < meetings.size()) {
            int time = meetings[i][2];
            vector<int> arr;
            while (i<meetings.size() && meetings[i][2] == time) {
                unionAll(meetings[i][0], meetings[i][1]);
                arr.push_back(meetings[i][0]);
                arr.push_back(meetings[i][1]);
                i++;
            }
            for (int p : arr) {
                if (getParent(0) != getParent(p))
                    reset(p);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (getParent(0) == getParent(i))
                ans.push_back(i);
        }
        return ans;
    }
};