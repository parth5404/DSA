class Solution {
public:
    long long maximumHappinessSum(vector<int>& happ, int k) {
        long long minus = 0;
        sort(happ.begin(), happ.end());
        int i = happ.size() - 1;
        long long ans = 0;
        while (i >= 0 && k > 0) {
            if (happ[i] - minus >= 0)
                ans = ans + happ[i] - minus;
            else
                ans = ans + 0;
            i--;
            k--;
            minus++;
        }
        return ans;
    }
};