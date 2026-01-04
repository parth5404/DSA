class Solution {
public:
    int countDivisors(int n) {
        int cnt = 0;
        int sum = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                if (i == n / i) {
                    cnt += 1;
                    sum += i;
                } else {
                    cnt += 2;
                    sum += i + n / i;
                }
            }
        }
        if (cnt == 4)
            return sum;
        return -1;
    }

    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (countDivisors(nums[i]) > 0)
                ans += countDivisors(nums[i]);
        }
        return ans;
    }
};