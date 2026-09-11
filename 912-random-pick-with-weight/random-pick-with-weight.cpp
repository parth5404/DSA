class Solution {
public:
    int cnt = 0;
    int idx = 0;
    int max_cnt = 0;
    vector<int> v;
    Solution(vector<int>& w) {
        for (int i = 0; i < w.size(); i++) {
            max_cnt += w[i];
            v.push_back(max_cnt);
        }
    }

    int pickIndex() {
        int target = rand() % (v.back())+1;
        int idx = lower_bound(v.begin(), v.end(), target) - v.begin();

        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */