class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->second.size() >= 3) {
                vector<int> arr = it->second;
                for (int i = 0; i < arr.size()-2; i++) {
                    ans = min(ans, abs(arr[i] - arr[i+1]) + abs(arr[i+1] - arr[i+2]) +
                                       abs(arr[i] - arr[i+2]));
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};