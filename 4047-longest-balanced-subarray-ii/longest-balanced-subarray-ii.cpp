class Solution {
    vector<int> segMin, segMax, lazy;
    int n;
    void propagate(int i, int l, int r) {
        if (lazy[i] != 0) {
            segMin[i] += lazy[i];
            segMax[i] += lazy[i];

            if (l != r) {
                lazy[2 * i + 1] += lazy[i];
                lazy[2 * i + 2] += lazy[i];
            }
            lazy[i] = 0;
        }
    }
    // Range add val to [start, end]
    void updateRange(int start, int end, int i, int l, int r, int val) {
        propagate(i, l, r); // make sure to propagate before hand

        if (l > end || r < start)
            return;

        //[start...end[ is fully inside range of current node [l..r]
        if (l >= start && r <= end) {
            lazy[i] += val;
            propagate(i, l, r);
            return;
        }

        int mid = (l + r) / 2;
        updateRange(start, end, 2 * i + 1, l, mid, val);
        updateRange(start, end, 2 * i + 2, mid + 1, r, val);

        segMin[i] = min(segMin[2 * i + 1], segMin[2 * i + 2]);
        segMax[i] = max(segMax[2 * i + 1], segMax[2 * i + 2]);
    }
    int findLeftMostZero(int i, int l, int r) {
        propagate(i, l, r);

        if (segMin[i] > 0 || segMax[i] < 0) {
            return -1;
        }

        if (l == r) {
            return l;
        }

        int mid = l + (r - l) / 2;
        int leftResult = findLeftMostZero(2 * i + 1, l, mid);
        if (leftResult != -1)
            return leftResult;

        return findLeftMostZero(2 * i + 2, mid + 1, r);
    }

public:
    int longestBalanced(vector<int>& nums) {
        this->n = nums.size();
        this->segMin.assign(4 * n, 0);
        this->segMax.assign(4 * n, 0);
        this->lazy.assign(4 * n, 0);
        int ans = 0;
        unordered_map<int, int> mp;
        vector<int> vec(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            int val = (nums[i] % 2 == 0) ? 1 : -1;
            if (mp.count(nums[i])) {
                int idx = mp[nums[i]];
                updateRange(0, idx, 0, 0, n - 1, -val);
            }
            updateRange(0, i, 0, 0, n - 1, val);

            int l = findLeftMostZero(0, 0, n - 1);
            if (l != -1)
                ans = max(ans, i - l + 1);
            mp[nums[i]] = i;
        }
        return ans;
    }
};