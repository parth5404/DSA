1class Solution {
2public:
3    long long totalScore(int hp, vector<int>& dam, vector<int>& req) {
4        long long ans = 0;
5        vector<long long> pref(dam.size() + 1);
6        for (int i = 1; i <= dam.size(); i++)
7            pref[i] = pref[i - 1] + dam[i - 1];
8        for (int i = 1; i <= dam.size(); i++) {
9            long long need = req[i - 1] + pref[i] - hp;
10            int lastip =
11                lower_bound(pref.begin(), pref.end(), need) - pref.begin();
12            // cout << need << " " << lastip << endl;
13            if (lastip + 1 > i)
14                continue;
15            lastip++;
16            ans += (i - lastip + 1);
17        }
18        return ans;
19    }
20};