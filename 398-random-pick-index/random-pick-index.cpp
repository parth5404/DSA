class Solution {
    unordered_map<int, vector<int>> mp;

public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]].push_back(i);
    }

    int pick(int target) {
        auto& vec = mp[target];
        int r = rand() % vec.size();
        return vec[r];
    }
};