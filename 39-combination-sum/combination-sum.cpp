class Solution {
public:
    vector<vector<int>> arr;
    void solve(vector<int>& nums, int idx, vector<int>& ds, int sum, int tar) {
        if (sum == tar) {
            arr.push_back(ds);
            return;
        }
        for (int i = idx; i < nums.size(); i++) {
            if (sum + nums[i] <= tar) {
                ds.push_back(nums[i]);
                solve(nums, i, ds, sum + nums[i], tar);
                ds.pop_back();
            } else {
                break;
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> ds;
        solve(nums, 0, ds, 0, target);
        return arr;
    }
};