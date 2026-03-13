class Solution {
public:
    int height;

    bool isCan(vector<int>& workerTimes, long long time) {
        long long val = 0;
        for (int t : workerTimes) {
            long long k = (2 * time) / t;
            long long x = (sqrt(1 + 4.0 * k) - 1) / 2;
            val += x;
            if (val >= height) return true;
        }
        return val >= height;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        height = mountainHeight;
        long long s = 0;
        long long e = 1e18;
        long long ans = e;
        while (s <= e) {
            long long mid = s + (e - s) / 2;
            if (isCan(workerTimes, mid)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return ans;
    }
};