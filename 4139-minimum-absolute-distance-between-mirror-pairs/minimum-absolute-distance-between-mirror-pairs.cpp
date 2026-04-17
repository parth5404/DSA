class Solution {
public:
    int reversee(int num) {
        string s = to_string(num);
        reverse(s.begin(), s.end());
        int j = 0;
        while (j < s.length() && s[j] == '0') j++;
        return stoi(s.substr(j));
    }
    
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        for (auto &p : mp) 
            sort(p.second.begin(), p.second.end());
        
        int ans = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            int rev = reversee(nums[i]);
            if (mp.find(rev) != mp.end()) {
                auto &vec = mp[rev];
                auto it = upper_bound(vec.begin(), vec.end(), i);
                if (it != vec.end()) 
                    ans = min(ans, *it - i);
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};
