class Solution {
public:
    void calcF(map<int, int>& f, long long i, long long& k) {
        while (k % i == 0) {
            k = k / i;
            f[i]++;
        }
    }
    int countSequences(vector<int>& nums, long long k) {
        map<int, int> f;
        long long kk = k;
        calcF(f, 2, kk);
        calcF(f, 3, kk);
        calcF(f, 5, kk);
        if (kk > 1)
            return 0;
        int n = nums.size();
        int half = n / 2;
        map<array<int, 3>, int> a, b;
        a[{0, 0, 0}] = 1;
        b[{0, 0, 0}] = 1;
        for (int i = 0; i <= half; i++) {
            map<array<int, 3>, int> v;
            int num = nums[i];
            int tw = 0;
            int th = 0;
            int f = 0;
            while (num % 2 == 0) {
                num = num / 2;
                tw++;
            }
            while (num % 3 == 0) {
                num = num / 3;
                th++;
            }
            while (num % 5 == 0) {
                num = num / 5;
                f++;
            }
            for (auto it : a) {
                v[it.first] += it.second;
                v[{it.first[0] + tw, it.first[1] + th, it.first[2] + f}] +=
                    it.second;
                v[{it.first[0] - tw, it.first[1] - th, it.first[2] - f}] +=
                    it.second;
            }
            a = v;
        }
        for (int i = half + 1; i < nums.size(); i++) {
            map<array<int, 3>, int> v;
            int num = nums[i];
            int tw = 0;
            int th = 0;
            int f = 0;
            while (num % 2 == 0) {
                num = num / 2;
                tw++;
            }
            while (num % 3 == 0) {
                num = num / 3;
                th++;
            }
            while (num % 5 == 0) {
                num = num / 5;
                f++;
            }
            for (auto it : b) {
                v[it.first] += it.second;
                v[{it.first[0] + tw, it.first[1] + th, it.first[2] + f}] +=
                    it.second;
                v[{it.first[0] - tw, it.first[1] - th, it.first[2] - f}] +=
                    it.second;
            }
            b = v;
        }
        int ans = 0;
        for (auto it : a) {
            int need2 = f[2] - it.first[0];
            int need3 = f[3] - it.first[1];
            int need5 = f[5] - it.first[2];
            ans += it.second * b[{need2, need3, need5}];
        }
        return ans;
    }
};