class Solution {
public:
    unordered_set<int> st1 = {2, 5, 6, 9};
    unordered_set<int> st2 = {0,1, 8};
    int rotatedDigits(int n) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            int num = i;
            bool inc = 0;
            while (num != 0) {
                if (!st1.count(num % 10) && !st2.count(num % 10)) {
                    inc = 0;
                    break;
                } else if (st1.count(num % 10))
                    inc = 1;
                num = num / 10;
            }
            if (inc)
                cnt++;
        }
        return cnt;
    }
};