class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            unordered_map<int, int> even;
            unordered_map<int, int> odd;
            for (int j = i; j < nums.size(); j++) {
                if (nums[j] % 2 == 0)
                    even[nums[j]]++;
                else
                    odd[nums[j]]++;

                if (even.size() == odd.size())
                    ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};