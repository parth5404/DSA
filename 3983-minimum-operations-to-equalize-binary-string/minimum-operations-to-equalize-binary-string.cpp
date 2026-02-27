class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();
        int zero = 0;
        set<int> odd;
        set<int> even;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0')
                zero++;
            (i % 2 == 0) ? even.insert(i) : odd.insert(i);
        }
        if (zero == 0)
            return 0;
        vector<int> opt(n + 1, -1);
        (zero % 2 == 0) ? even.erase(zero) : odd.erase(zero);
        opt[zero] = 0;
        queue<int> q;
        q.push(zero);
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            int minF = max(0, k + top - n);
            int maxF = min(k, top);
            int z_min = top + k - 2 * maxF;
            int z_max = top + k - 2 * minF;
            auto& st = (z_min % 2 == 0) ? even : odd;
            auto it = st.lower_bound(z_min);
            while (it != st.end()) {
                int val = *it;
                if (val > z_max)
                    break;
                if (opt[val] == -1) {
                    opt[val] = opt[top] + 1;
                    if (val == 0)
                        return opt[0];
                    q.push(val);
                }
                it=st.erase(it);
                //it++;
            }
        }
        return -1;
    }
};