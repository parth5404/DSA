class Solution {
public:
    int lcs(vector<int>& arr) {
        unordered_set<int> st(arr.begin(), arr.end());
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            int cons = 1;
            int x = arr[i] + 1;
            if(st.find(arr[i]-1)!=st.end())continue;
            while (st.find(x) != st.end()) {
                cons++;
                x++;
            }
            ans = max(ans, cons);
        }
        return ans;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                               vector<int>& vBars) {
        int a1 = lcs(hBars)+1;
        int a2 = lcs(vBars)+1;
        return min(a1, a2) * min(a1, a2);
    }
};