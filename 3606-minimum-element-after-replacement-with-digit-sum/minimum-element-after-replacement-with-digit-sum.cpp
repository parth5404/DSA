class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans=INT_MAX;
        for(auto it:nums){
            int sum=0;
            while(it!=0){
                sum+=(it%10);
                it=it/10;
            }
            ans=min(ans,sum);
        }
        return ans;
    }
};