class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_el = *max_element(nums.begin(), nums.end());
        int mves = 0;
        for (auto it : nums) {
            mves += (max_el - it);
        }
        return mves;
    }
};