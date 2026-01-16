class Solution {
public:
    int mod = 1e9 + 7;
    unordered_set<int> create(vector<int>& arr) {
        unordered_set<int> st;
        int last = arr.size() - 1;
        while (last >= 0) {
            for (int i = 0; i < last; i++) {
                st.insert(arr[last] - arr[i]);
            }
            last--;
        }
        return st;
    }
    int maximizeSquareArea(int m, int n, vector<int>& hFences,
                           vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        unordered_set<int> st1 = create(hFences);
        unordered_set<int> st2 = create(vFences);
        long long ans = 0;
        bool flag = 1;
        for (auto it : st1) {
            if (st2.find(it) != st2.end()) {
                flag = 0;
                long long val = (1LL * it * it);
                ans = max(ans, val);
            }
        }
        if (flag)
            return -1;
        return ans % mod;
    }
};