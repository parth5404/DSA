class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int se = 1e9;
        int so = 1e9;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 1)
                so = min(so, nums[i]);
            else
                se = min(se, nums[i]);
        }
        if (se == 1e9 || so == 1e9)
            return true;
        bool oko = true;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                if (nums[i] - so < 1) {
                    oko = false;
                }
            } 
        }
        return oko ;
    }
};