class Solution {
public:
    int palat(int nums) {
        string s = to_string(nums);
        reverse(s.begin(), s.end());
        int i = 0;
        while (i < s.length() && s[i] == '0')
            i++;
        string res = s.substr(i);
        return res.empty() ? 0 : stoi(res);
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int num1 = palat(nums[i]);

            if (mp.count(num1)) {
                 auto &vec = mp[num1];
                auto it = upper_bound(vec.begin(), vec.end(), i);
                if (it != vec.end()) 
                    ans = min(ans, *it - i);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};