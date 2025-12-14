class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ss=0;
        int ls=0;
        for(int i=0;i<k;i++){
            ss+=nums[i];
            ls+=nums[nums.size()-1-i];
        }
        return abs(ls-ss);
    }
};