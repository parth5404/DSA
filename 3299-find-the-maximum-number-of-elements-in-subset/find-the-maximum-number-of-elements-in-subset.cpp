class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int ans = 1;
        unordered_map<long long, int> mp;
        for (auto i : nums) {
            mp[i]++;
        }
        ans=max(ans,mp[1]-(mp[1]%2==0));
        for (auto& [k, v] : mp) {
            if (k == 1) {
                continue;
            }
            if (v >= 2) {
                int len = 2;
                long long need = k * k;
                while (mp.contains(need) && mp[need] >= 2) {
                    need = need * need;
                   // cout << need << endl;
                    len += 2;
                }
                if (mp.count(need)) {
                    len += 1;
                    ans = max(ans, len);
                } else {
                    len -= 1;
                    ans = max(ans, len);
                }
            }
        }
        return ans;
    }
};