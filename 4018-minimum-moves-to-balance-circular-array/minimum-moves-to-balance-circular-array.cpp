class Solution {
public:
    long long minMoves(vector<int>& balance) {
        long long sum = 0;
        
        int n = balance.size();
        int idx = -1;
        for (int i = 0; i < balance.size(); i++) {
            sum+=balance[i];
            if (balance[i] < 0)
                idx = i;
        }
        if (sum < 0)
            return -1;
        if (idx == -1)
            return 0;
        int width = 1;
        int left = (idx - width + n) % n;
        int right = (idx + width) % n;
        long long ans = 0;
        long long val = balance[idx];
        while (val < 0) {
            if (balance[left] > 0) {
                long long need = min((long long) balance[left], -val);
                val += need;
                ans += need*width;
            }
            if (val < 0 && balance[right] > 0) {
                long long need = min((long long) balance[right], -val);
                val += need;
                ans += need*width;
            }
            width++;
            left = (idx - width + n) % n;
            right = (idx + width) % n;
        }
        return ans;
    }
};