class ST {
public:
    vector<int> arr;
    vector<int> st;
    bool isMin;
    ST(vector<int> nums, bool flag) {
        this->arr = nums;
        this->isMin = flag;
        st.resize(4 * arr.size());
        buildst(0, 0, nums.size() - 1);
    }
    void buildst(int i, int s, int e) {
        if (s == e) {
            st[i] = arr[s];
            return;
        }
        int mid = s + (e - s) / 2;
        buildst(2 * i + 1, s, mid);
        buildst(2 * i + 2, mid + 1, e);
        if (isMin)
            st[i] = min(st[2 * i + 1], st[2 * i + 2]);
        else
            st[i] = max(st[2 * i + 1], st[2 * i + 2]);
    }
    long long Query(int a, int b, int l, int r, int i) {
        if (l > b || r < a)
            return isMin ? INT_MAX : INT_MIN;
        if (l >= a && r <= b)
            return st[i];
        int mid = l + (r - l) / 2;
        int k1 = Query(a, b, l, mid, 2 * i + 1);
        int k2 = Query(a, b, mid + 1, r, 2 * i + 2);
        return isMin ? min(k1, k2) : max(k1, k2);
    }
};

class Solution {
public:
    priority_queue<tuple<long long, int, int>> pq;
    long long maxTotalValue(vector<int>& nums, int k) {
        ST* minSt = new ST(nums, 1);
        ST* maxST = new ST(nums, 0);
        int n = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++) {
            long long val =
                maxST->Query(i, n, 0, n, 0) - minSt->Query(i, n, 0, n, 0);
            pq.push({val, i, n});
        }
        long long ans = 0;
        // if (pq.size() >= k) {
        //     while (k--) {
        //         auto [val, l, r] = pq.top();
        //         ans += val;
        //         pq.pop();
        //         // long long val1 = maxST->Query(l, r - 1, 0, n, 0) -
        //         //                  minSt->Query(l, r - 1, 0, n, 0);
        //         // pq.push({val1, l, r - 1});
        //     }
        // } else {
        while (k--) {
            auto [val, l, r] = pq.top();
            ans += val;
            pq.pop();
            long long val1 = maxST->Query(l, r - 1, 0, n, 0) -
                             minSt->Query(l, r - 1, 0, n, 0);
            pq.push({val1, l, r - 1});
        }
        //}

        return ans;
    }
};