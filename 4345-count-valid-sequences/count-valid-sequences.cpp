class Solution {
public:
    int MOD = 1e9 + 7;
    vector<long long> fact;
    vector<long long> invFact;

    // calculates x^(MOD-2) % MOD
    long long modPow(long long val) {
        long long ans = 1;
        long long k = MOD - 2;

        while (k > 0) {
            if (k & 1)
                ans = (ans * val) % MOD;

            val = (val * val) % MOD;
            k >>= 1;
        }

        return ans;
    }

    void popFact(int n) {
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        invFact[n] = modPow(fact[n]);

        for (int i = n - 1; i >= 0; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }
    }

    int calcFact(int n, int k) {
        if (n < 0 || k < 0 || k > n)
            return 0;

        return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
    }

    int countValidSequences(int n, int k) {
        fact.assign(n + 1, 0);
        invFact.assign(n + 1, 0);

        popFact(n);

        long long ans1 = calcFact(n - 1, k - 1);
        long long odd = 0;
        if ((n - k) % 2 == 0) {
            int m = (n - k) / 2;
            odd = calcFact(m + k - 1, k - 1);
        }

        return (ans1 - odd + MOD) % MOD;
    }
};