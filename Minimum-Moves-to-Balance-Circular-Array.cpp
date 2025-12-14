1class Solution {
2public:
3    long long minMoves(vector<int>& balance) {
4        long long sum = 0;
5        
6        int n = balance.size();
7        int idx = -1;
8        for (int i = 0; i < balance.size(); i++) {
9            sum+=balance[i];
10            if (balance[i] < 0)
11                idx = i;
12        }
13        if (sum < 0)
14            return -1;
15        if (idx == -1)
16            return 0;
17        int width = 1;
18        int left = (idx - width + n) % n;
19        int right = (idx + width) % n;
20        long long ans = 0;
21        long long val = balance[idx];
22        while (val < 0) {
23            if (balance[left] > 0) {
24                long long need = min((long long) balance[left], -val);
25                val += need;
26                ans += need*width;
27            }
28            if (val < 0 && balance[right] > 0) {
29                long long need = min((long long) balance[right], -val);
30                val += need;
31                ans += need*width;
32            }
33            width++;
34            left = (idx - width + n) % n;
35            right = (idx + width) % n;
36        }
37        return ans;
38    }
39};