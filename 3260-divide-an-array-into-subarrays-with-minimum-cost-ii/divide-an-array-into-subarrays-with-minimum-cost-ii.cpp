class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        long long sum = 0;
        long long ans = LLONG_MAX;

        set<pair<int, int>> el;
        set<pair<int, int>> max_el;

        int i = 1;

        while (i - dist < 1) {
            el.insert({nums[i], i});
            sum += nums[i];

            if ((int)el.size() > k - 1) {
                auto p = *el.rbegin();
                sum -= p.first;
                max_el.insert(p);
                el.erase(p);
            }
            i++;
        }

        while (i < nums.size()) {
            el.insert({nums[i], i});
            sum += nums[i];

            if ((int)el.size() > k - 1) {
                auto p = *el.rbegin();
                sum -= p.first;
                max_el.insert(p);
                el.erase(p);
            }

            ans = min(ans, sum);

            pair<int, int> rem = {nums[i - dist], i - dist};

            if (el.count(rem)) {
                el.erase(rem);
                sum -= rem.first;

                if (!max_el.empty()) {
                    auto p = *max_el.begin(); // smallest from max_el
                    el.insert(p);
                    sum += p.first;
                    max_el.erase(p);
                }
            } else {
                max_el.erase(rem);
            }
            i++;
        }

        return nums[0] + ans;
    }
};
