class Solution {
public:
    bool isPrime(int n) {
        if (n == 1)
            return 0;
        for (int i = 2; i < n; i++) {
            if (n % i == 0)
                return 0;
        }
        return 1;
    }
    int countPrimeSetBits(int left, int right) {
        int cnt = 0;
        while (left <= right) {
            int bits = 0;
            int val = left;
            while (val != 0) {
                if (val & 1 == 1)
                    bits++;
                val = val / 2;
            }
            if (isPrime(bits)) {
                cout << left << endl;
                cnt++;
            }
            left++;
        }
        return cnt;
    }
};